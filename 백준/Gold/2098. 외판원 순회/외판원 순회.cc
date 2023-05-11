#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 987654321;
int n, w[16][16], dp[16][1<<16];

int tsp(int cur, int visit) {
	if (visit == ((1<<n)-1)) {
		if (w[cur][0] == 0) return INF;
		else return w[cur][0];
	}

	if (dp[cur][visit] != -1) return dp[cur][visit];

	dp[cur][visit] = INF;
	for (int nxt = 0; nxt < n; nxt++) {
		if (w[cur][nxt] == 0) continue;
		if ((visit >> nxt) & 1) continue;

		dp[cur][visit] = min(dp[cur][visit], w[cur][nxt]+tsp(nxt, visit | (1<<nxt)));
	}
	return dp[cur][visit];	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	for (int i = 0; i < n; i++)
		fill(dp[i], dp[i] + (1 << n), -1);
	
	cout << tsp(0, 1);
}