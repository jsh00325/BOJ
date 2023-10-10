#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

ll mpow(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD, b >>= 1;
	} return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll ans = 0;
	int q; cin >> q;
	while (q--) {
		ll a, b; cin >> a >> b;
		ans = (ans + (b * mpow(a, MOD-2)) % MOD) % MOD;
	} cout << ans;	
}