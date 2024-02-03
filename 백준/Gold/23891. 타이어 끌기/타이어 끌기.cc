#include <bits/stdc++.h>
using namespace std;

int n, m, dp[101][100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int s, p; cin >> s >> p;
		for (int j = 0; j <= m; ++j) dp[i][j] = dp[i-1][j]-s;
		for (int j = p; j <= m; ++j) dp[i][j] = max(dp[i][j], dp[i-1][j-p]);
		for (int j = p+1; j <= m; ++j) dp[i][j] = max(dp[i][j], dp[i-1][j-p-1]+s);
	}
	int mx = dp[n][0];
	for (int i = 1; i <= m; ++i) mx = max(mx, dp[n][i]);
	cout << (mx > 0 ? "W" : (mx == 0 ? "D" : "L"));
}