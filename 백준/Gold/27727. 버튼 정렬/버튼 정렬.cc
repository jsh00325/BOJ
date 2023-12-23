#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, ok, k, ans;
vector<ll> v0, v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n; v0.resize(n); v.resize(n);
	for (int i = 0; i < n; ++i) cin >> v0[i], v[i] = v0[i];
	cin >> k; ok = k;

	ll prev = v[0];
	for (int i = 1; i < n; ++i) prev = (prev > v[i] ? v[i] = prev : v[i]);
	for (int i = n-1; i >= 0; --i) if (v0[i] != v[i]) {
		for (int j = i; j >= 0; --j) v[j] = v[i], k -= (v[j] - v0[j]);
		break;
	}

	if (k < 0) { cout << ans; return 0; }
	if (ok != k) ans = 1;
	if (k == 0) { cout << ans; return 0; }
	for (int i = 1; i < n; ++i) if (k > 0 && v[i-1] != v[i]) {
		ll dif = v[i] - v[i-1], len = i;
		if (dif * len <= k) k -= dif * len, ans += dif;
		else ans += k / len, k = 0;		
	} cout << ans + k / n;
}