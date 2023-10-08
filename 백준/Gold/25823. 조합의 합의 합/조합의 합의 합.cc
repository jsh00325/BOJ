#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7, MX = 4*1e5;
ll fact[MX+1], ans = 0;

ll mpow(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	} return ans;
}
ll comb(ll n, ll r) {
	return (fact[n] * mpow((fact[r] * fact[n - r]) % MOD, MOD - 2)) % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= MX; ++i) fact[i] = (fact[i-1] * i) % MOD;
	int n; cin >> n; for (int i = 3; i <= n; ++i) ans = (ans + comb(2*i, i)) % MOD;
	cout << ans;	
}