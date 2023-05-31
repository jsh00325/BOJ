#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, mem[103], c[103], dp[103][10003];

int solve() {
	for (int i = 0; i <= 10000; i++) if (dp[n][i] >= m) return i;
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> mem[i];
	for (int i = 1; i <= n; i++) cin >> c[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			dp[i][j] = dp[i-1][j];
			if (j - c[i] < 0) continue;
			dp[i][j] = max(dp[i][j], mem[i] + dp[i-1][j-c[i]]);
		}
	}
	cout << solve();	
}