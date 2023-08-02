#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(register int (i) = 0; (i) < (n); ++(i))

int n, m, a[3001], b[101];
int dp[3001][2][101][101];

inline void max_update(int& cur, const int& nxt) { if (cur < nxt) cur = nxt; }
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	cin >> n; FOR(i, n) cin >> a[i];
	cin >> m; FOR(i, m) cin >> b[i];
	sort(b, b + m, [](const int& a, const int& b) {return a > b; });
	FOR(ai, n + 1) FOR(l, m + 1) FOR(s, m + 1) {
		if (ai) {
			max_update(dp[ai][1][l][s], dp[ai - 1][0][l][s] + a[ai - 1]);
			max_update(dp[ai][0][l][s], dp[ai - 1][1][l][s]);
		}
		if (l) max_update(dp[ai][1][l][s], dp[ai][0][l - 1][s] + b[l - 1]);
		if (s) max_update(dp[ai][0][l][s], dp[ai][1][l][s - 1]);
		max_update(dp[ai][1][l][s], dp[ai][0][l][s]);
	}

	int ans = 0;
	FOR(l, m + 1) max_update(ans, dp[n][1][l][m - l]);
	cout << ans;
}