#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

const int INF = 0x6fffffff;
int n, w, dp[1005][1005], ans[1005];
pii from[1005][1005];

int dist(const int x, const int y, const vector<pii> &loc) {
	return abs(loc[x].X - loc[y].X) + abs(loc[x].Y - loc[y].Y);
}
void print_ans() {
	int mn = INF; pii cood = { 0,0 };
	for (int i = 0; i < w + 1; i++) if (mn > dp[i][w+1]) { mn = dp[i][w+1]; cood = {i,w+1}; }
	for (int j = 0; j < w + 1; j++) if (mn > dp[w+1][j]) { mn = dp[w+1][j]; cood = {w+1,j}; }
	cout << mn;

	for (int x = w + 1; x >= 1; x--) {
		ans[x] = (cood.X == x ? 1 : 2);
		cood = from[cood.X][cood.Y];
	}
	for (int i = 2; i < w + 2; i++) cout << '\n' << ans[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> w;
	vector<pii> loc(w + 2);
	loc[0] = { 1,1 };
	loc[1] = { n,n };
	for (int i = 0; i < w; i++) cin >> loc[i + 2].X >> loc[i + 2].Y;

	for (int i = 0; i < w + 2; i++) fill(dp[i], dp[i] + w + 2, INF);
	dp[0][1] = 0;
	for (int i = 0; i < w + 2; i++) {
		for (int j = 1; j < w + 2; j++) {
			int nxt = max(i, j) + 1;
			if (i == j || nxt >= w + 2) continue;

			if (dp[nxt][j] > dp[i][j] + dist(i, nxt, loc)) {
				dp[nxt][j] = dp[i][j] + dist(i, nxt, loc);
				from[nxt][j] = {i, j};
			}
			if (dp[i][nxt] > dp[i][j] + dist(j, nxt, loc)) {
				dp[i][nxt] = dp[i][j] + dist(j, nxt, loc);
				from[i][nxt] = {i, j};
			}
		}
	}
	print_ans();
}