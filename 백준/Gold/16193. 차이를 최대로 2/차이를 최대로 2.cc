#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node { int idx, val; } arr[4];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, fr, bk, st, en; cin >> n;
	vector<int> v(n); for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	ll ans = 0; fr = bk = v[0], st = 1, en = n-1;
	while (st <= en) {
		arr[0] = {0, abs(v[st] - fr)}, arr[1] = {1, abs(v[st] - bk)};
		arr[2] = {2, abs(v[en] - bk)}, arr[3] = {3, abs(v[en] - fr)};
		sort(arr, arr+4, [](const node& a, const node& b){ return a.val > b.val; });

		switch(arr[0].idx) {
			case 0 : fr = v[st++]; break;
			case 1 : bk = v[st++]; break;
			case 2 : bk = v[en--]; break;
			case 3 : fr = v[en--]; break;
		} ans += arr[0].val;
	} cout << ans;
}