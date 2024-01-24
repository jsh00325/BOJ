#include <bits/stdc++.h>
using namespace std;

int n, m, t;
bool dp[1001][10001] = {1, };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	vector<int> d(n+1); for (int i = 1; i <= n; ++i) cin >> d[i];
	for (int r = 1; r <= n; ++r) for (int i = 0; i < d[r]; ++i) {
		cin >> t; for (int c = m; c >= t; --c) if (dp[r-1][c-t] || dp[r][c-t]) dp[r][c] = 1;
	}

	int ans = -1;
	for (int i = m; i >= 1; --i) if (dp[n][i]) {
		ans = i; break;
	} cout << ans;
}