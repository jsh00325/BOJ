#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, arr[10001];
ll solve(ll x) {
	ll ans = m;
	for (int i = 1; i <= m; i++) ans += x / arr[i];
	return ans;
}

int solve2(ll prv, ll time) {
	for (int i = 1; i <= n; i++) {
		if (time % arr[i]) continue;
		if (++prv == n) return i;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> arr[i];

	ll st = 0, en = 6 * 1e10 + 5;
	while (st < en) {
		ll mid = (st + en) / 2;

		if (solve(mid) >= n) en = mid;
		else st = mid + 1;
	}

	if (st) cout << solve2(solve(st - 1), st);
	else cout << n;
}