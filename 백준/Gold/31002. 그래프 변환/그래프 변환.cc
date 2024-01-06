#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll k, dp[100001];

ll reci(ll a) {
	ll ans = 1, b = MOD - 2;
	while (b > 0) {
		if (b & 1) ans = (ans * a) % MOD;
		b >>= 1, a = (a * a) % MOD;
	} return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> dp[0] >> k;
	dp[1] = ((dp[0] * (dp[0] - 1)) / 2) % MOD;
	for (int i = 2; i <= k; ++i)
		dp[i] = (dp[i-1] * (2 * (dp[i-1] * reci(dp[i-2])) % MOD + MOD - 1) % MOD) % MOD;
	cout << dp[k];	
}