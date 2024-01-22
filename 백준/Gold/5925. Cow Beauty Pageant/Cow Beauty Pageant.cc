#include <bits/stdc++.h>
using namespace std;
struct node { int x, y, dist; };

int n, m, area[50][50], dist[3][3];
string arr[50];

inline bool oob(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
void dfs(int i, int j, int flag) {
	for (int dir = 0; dir < 4; ++dir) {
		int ni = i + ("1012"[dir]-'1'), nj = j + ("0121"[dir]-'1');
		if (oob(ni, nj) || arr[ni][nj] == '.' || area[ni][nj]) continue;
		area[ni][nj] = flag; dfs(ni, nj, flag);
	}
}

int bfs(int st, int en) {
	queue<node> q; bool vst[50][50] = {0, };
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (area[i][j] == st) q.push({i, j, 0}), vst[i][j] = true;

	while(!q.empty()) {
		node cur = q.front(); q.pop();
		if (area[cur.x][cur.y] == en) return cur.dist - 1;

		for (int dir = 0; dir < 4; ++dir) {
			int ni = cur.x + ("1012"[dir]-'1'), nj = cur.y + ("0121"[dir]-'1');
			if (oob(ni, nj) || vst[ni][nj]) continue;
			q.push({ni, nj, cur.dist + 1}), vst[ni][nj] = true;
		}
	}
}
int bfs2(int i, int j) {
	queue<node> q; bool vst[50][50] = {0, };
	q.push({i, j, 0}); vst[i][j] = true;
	int fin = 0, ans = 0;

	while (!q.empty()) {
		node cur = q.front(); q.pop();
		if (!((fin >> area[cur.x][cur.y]) & 1)) {
			ans += cur.dist, fin |= (1 << area[cur.x][cur.y]);
			if (fin == 0b1111) return ans - 2;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ni = cur.x + ("1012"[dir]-'1'), nj = cur.y + ("0121"[dir]-'1');
			if (oob(ni, nj) || vst[ni][nj]) continue;
			q.push({ni, nj, cur.dist + 1}), vst[ni][nj] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int area_cnt = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
		if (!area[i][j] && arr[i][j] != '.') area[i][j] = ++area_cnt, dfs(i, j, area_cnt);

	int a = bfs(1, 2), b = bfs(1, 3), c = bfs(2, 3);
	int sol = a + b + c - max(a, max(b, c));

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (!area[i][j])
		sol = min(sol, bfs2(i, j));
	cout << sol;
}