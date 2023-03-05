#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3fffffff;
int cost[5][5] = { {-1,2,2,2,2}, {-1,1,3,4,3},{-1,3,1,3,4},{-1,4,3,1,3},{-1,3,4,3,1} };
int dp[100003][5][5];
vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int k; cin >> k;
		if (k) a.push_back(k);
		else break;
	}

	if (a.empty()) {
		cout << 0;
		return 0;
	}

	for (int k = 0; k < a.size(); k++)
		for (int i = 0; i < 4; i++)
			for (int j = i + 1; j < 5; j++)
				dp[k][i][j] = INF;
	dp[0][0][a[0]] = 2;

	for (int k = 0; k < a.size() - 1; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 5; j++) {
				if (dp[k][i][j] == INF) continue;
				if (a[k+1] != j) {
					int ni = min(a[k+1], j), nj = max(a[k+1], j);
					dp[k + 1][ni][nj] = min(dp[k + 1][ni][nj], dp[k][i][j] + cost[i][a[k+1]]);
                }
				if (a[k+1] != i) {
					int ni = min(a[k+1], i), nj = max(a[k+1], i);
					dp[k + 1][ni][nj] = min(dp[k + 1][ni][nj], dp[k][i][j] + cost[j][a[k+1]]);
				}
			}

		}
	}

	int ans = INF;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			ans = min(ans, dp[a.size() - 1][i][j]);
	cout << ans;
}