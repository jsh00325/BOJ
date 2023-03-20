#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)

const int MX = 500000;
int n, x, arr[MX+1], sorted[MX+1];
ll ans, fenwick[MX + 1];

void update(int idx) {
	while (idx <= n) {
		fenwick[idx]++;
		idx += idx & (-idx);
	}
}
ll query(int idx) { // prefix sum of [1, idx]
	ll rslt = 0;
	while (idx > 0) {
		rslt += fenwick[idx];
		idx -= idx & (-idx);
	}
	return rslt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR1(i, n) {
		cin >> arr[i];
		sorted[i] = arr[i];
	}
	sort(sorted + 1, sorted + n + 1);

	FOR1(i, n) {
		int idx = lower_bound(sorted + 1, sorted + n + 1, arr[i]) - sorted;
		ans += (i - 1) - query(idx);
		update(idx);
	}
	cout << ans;
}