#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, all_sum, arr[100007], p, q, r, s;

bool solve(ll k) {
	ll ret = all_sum;
	ret -= p * (n - (upper_bound(arr, arr+n, k+r) - arr));
	ret += q * (lower_bound(arr, arr+n, k) - arr);
	return ret >= s;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) { cin >> arr[i]; all_sum += arr[i]; }
	cin >> p >> q >> r >> s;
	sort(arr, arr+n);

	ll st = 1, en = 111111;
	while (st + 1 < en) {
		ll mid = (st + en) >> 1;
		if (solve(mid)) en = mid;
		else st = mid;
	}
	if (solve(st)) cout << st;
	else cout << (solve(en) ? en : -1);
}