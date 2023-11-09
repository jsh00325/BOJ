#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll comb[52][52], sum[51];

ll mpow(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD, b >>= 1;
	} return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll n, k; cin >> n >> k;
	sum[0] = n;
	for (int i = 0; i < 52; ++i) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; ++j) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
	}

	// (i + 1) * sum[i] = ((n+1)^(i+1) - 1) - sigma_(j=0 ~ i-1) comb[i+1][j] * sum[j]
	for (int i = 1; i <= k; ++i) {
		ll ans = (mpow(n+1, i+1) + MOD - 1) % MOD;
		for (int j = 0; j < i; ++j) ans = (ans + MOD - (comb[i+1][j] * sum[j]) % MOD) % MOD;
		sum[i] = (ans * mpow(i+1, MOD - 2)) % MOD;
	} cout << sum[k];
}