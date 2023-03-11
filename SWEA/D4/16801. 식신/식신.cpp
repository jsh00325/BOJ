#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> a, f;

bool cmp(const ll& x, const ll& y) { return x > y; }
bool solve(ll x) {
	ll cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] * f[i] > x) cnt += a[i] - (x / f[i]);
	return cnt <= k;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> k;
		a.resize(n); f.resize(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> f[i];
		sort(a.begin(), a.end());
		sort(f.begin(), f.end(), cmp);

		ll st = 0, en = a[n - 1] * f[0];
		while (st < en) {
			ll mid = (st + en) / 2;

			if (solve(mid)) en = mid;
			else st = mid + 1;
		}
		cout << '#' << t << ' ' << st << '\n';
	}
    return 0;
}