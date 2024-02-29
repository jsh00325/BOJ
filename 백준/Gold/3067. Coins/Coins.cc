#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		int m; cin >> m;

		memset(dp, 0, sizeof(dp)); dp[0] = 1;
		for (int w : v) for (int i = w; i <= m; ++i) dp[i] += dp[i-w];
		cout << dp[m] << '\n';
	}
}