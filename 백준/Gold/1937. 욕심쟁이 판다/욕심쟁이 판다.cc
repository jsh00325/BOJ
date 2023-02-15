#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
int n, map[503][503], dp[503][503];
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

int dfs(int i, int j) {
	if (dp[i][j]) return dp[i][j];

	dp[i][j] = 1;
	FOR(dir, 4) {
		int ni = i+di[dir], nj = j+dj[dir];
		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		if (map[i][j] >= map[ni][nj]) continue;
		dp[i][j] = max(dp[i][j], dfs(ni, nj)+1);
	}
	return dp[i][j];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, n)FOR(j, n) cin >> map[i][j];

	int mx = 0;
	FOR(i, n)FOR(j, n) mx = max(mx, dfs(i,j));
	cout << mx;
}