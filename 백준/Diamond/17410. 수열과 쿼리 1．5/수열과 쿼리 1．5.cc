#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

const int m = 650;
int n, arr[100001];
struct Bucket { int arr[m], size; } buc[160];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR(i, n) cin >> arr[i];
	FOR(i, n) buc[i / m].arr[buc[i / m].size++] = arr[i];
	FOR(i, n / m + 1) if (buc[i].size) sort(buc[i].arr, buc[i].arr + buc[i].size);

	int q; cin >> q;
	while (q--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int i, v; cin >> i >> v;
			int iB = (--i) / m;
			Bucket& curBuc = buc[iB];
			int idx = upper_bound(curBuc.arr, curBuc.arr + curBuc.size, arr[i]) - curBuc.arr;
			for (int cur = idx; cur < curBuc.size; ++cur) curBuc.arr[cur-1] = curBuc.arr[cur];
			idx = upper_bound(curBuc.arr, curBuc.arr + curBuc.size - 1, v) - curBuc.arr;
			for (int cur = curBuc.size - 2; cur >= idx; --cur) curBuc.arr[cur+1] = curBuc.arr[cur];
			curBuc.arr[idx] = arr[i] = v;
		}
		else {
			int i, j, k; cin >> i >> j >> k;
			int iB = (--i) / m, jB = (--j) / m;

			cout << [&] () {
				int ans = 0;
				if (iB == jB) {
					for (int cur = i; cur <= j; ++cur) if (arr[cur] > k) ++ans;
					return ans;
				}
				for (int cur = i; cur < m * (iB + 1); ++cur) if (arr[cur] > k) ++ans;
				for (int cur = m * jB; cur <= j; ++cur) if (arr[cur] > k) ++ans;
				for (int cB = iB + 1; cB < jB; ++cB)
					ans += (buc[cB].arr + buc[cB].size - upper_bound(buc[cB].arr, buc[cB].arr + buc[cB].size, k));
				return ans;
			} () << '\n';
		}
	}
}