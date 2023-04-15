#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

typedef struct { int x, y, dist, broken; } Node;
string arr[1000];
int n, m, di[4] = {0,1,0,-1}, dj[4] = {1,0,-1,0};
queue<Node> q;
bool visit[1000][1000][2];

inline bool oob(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
int bfs() {
	q.push({ 0,0,1,0 }); visit[0][0][0] = true;
	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		if (cur.x == n - 1 && cur.y == m - 1) return cur.dist;

		FOR(dir, 4) {
			int ni = cur.x + di[dir], nj = cur.y + dj[dir];
			if (oob(ni, nj)) continue;
			if (arr[ni][nj] == '1') continue;
			if (visit[ni][nj][cur.broken]) continue;
			q.push({ ni ,nj, cur.dist + 1, cur.broken });
			visit[ni][nj][cur.broken] = true;
		}
		if (cur.broken) continue;
		FOR(dir, 4) {
			int ni = cur.x + di[dir], nj = cur.y + dj[dir];
			if (oob(ni, nj)) continue;
			if (arr[ni][nj] == '0') continue;
			if (visit[ni][nj][1]) continue;
			q.push({ ni ,nj, cur.dist + 1, 1 });
			visit[ni][nj][1] = true;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR(i, n) cin >> arr[i];
	cout << bfs();
}