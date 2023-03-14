#include <bits/stdc++.h>
using namespace std;
    
typedef pair<int, int> pii;
#define X first
#define Y second

int n, m, di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0};
vector<pii> adj[101][101];
bool light[101][101], visit[101][101];

inline bool oob(int i, int j) { return i < 1 || i > n || j < 1 || j > n; }
int solve() {
	int ans = 1; light[1][1] = true;
	queue<pii> q;
	q.push({ 1, 1 }); visit[1][1] = true; 

	while (!q.empty()) {
		pii cur = q.front(); q.pop();

		bool flag = false;
		for (pii nxt : adj[cur.X][cur.Y]) {
			if (!light[nxt.X][nxt.Y]) {
				ans++; flag = true;
			}
			light[nxt.X][nxt.Y] = true;
		}
		if (flag) {
			memset(visit, false, sizeof(visit));
			visit[cur.X][cur.Y] = true;
		}

		for (int dir = 0; dir < 4; dir++) {
			int ni = cur.X + di[dir], nj = cur.Y + dj[dir];
			if (oob(ni, nj)) continue;
			if (!light[ni][nj]) continue;
			if (visit[ni][nj]) continue;

			q.push({ ni, nj }); visit[ni][nj] = true;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		adj[x][y].push_back({ a, b });
	}
	cout << solve();
}