#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

const int INF = 0x3fffffff;
int m, n, l, g, di[2] = { 0, 1 }, dj[2] = { 1, 0 };
int side[100][100], down[100][100], dp[100][100][200][2];

inline bool oob(int i, int j) { return i >= n || j >= m; }
inline void set_min(int& a, int b) { a = min(a, b); }
int solve() {
	FOR(turn, 200) FOR(dir, 2)
		if (dp[n - 1][m - 1][turn][dir] <= g) return (n + m - 2) * l + turn;
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> l >> g;
		FOR(i, n) FOR(j, m - 1) cin >> side[i][j];
		FOR(i, n - 1) FOR(j, m) cin >> down[i][j];

		// init
		FOR(i, 100) FOR(j, 100) FOR(k, 200) FOR(dir, 2) dp[i][j][k][dir] = INF;

		// base
		dp[0][0][0][0] = dp[0][0][0][1] = 0;

		FOR(i, n) FOR(j, m) FOR(turn, 200) FOR(dir, 2) {
			if (dp[i][j][turn][dir] == INF) continue;
			FOR(n_dir, 2) {
				int ni = i + di[n_dir], nj = j + dj[n_dir];
				if (oob(ni, nj)) continue;
				int w = n_dir ? down[i][j] : side[i][j];
				set_min(dp[ni][nj][turn + (dir != n_dir)][n_dir], dp[i][j][turn][dir] + w);
			}
		}
		cout << solve() << '\n';
	}
}