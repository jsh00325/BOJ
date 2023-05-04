#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

typedef struct { int x, y; } Node;
int n, m, arr[8][8];
int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };
bool visit[8][8];
queue<Node> q;

inline bool oob(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
int bfs() {
	MEM(visit, false);
	FOR(i, n) FOR(j, m) if (arr[i][j] == 2) {
		q.push({ i, j }); visit[i][j] = true;
		while (!q.empty()) {
			Node cur = q.front(); q.pop();
			FOR(dir, 4) {
				int ni = cur.x + di[dir], nj = cur.y + dj[dir];
				if (oob(ni, nj)) continue;
				if (arr[ni][nj]) continue;
				if (visit[ni][nj]) continue;
				q.push({ ni, nj }); visit[ni][nj] = true;
			}
		}
	}
	int cnt = 0;
	FOR(i, n) FOR(j, m) if (arr[i][j] == 0 && !visit[i][j]) cnt++;
	return cnt;
}
int backtracking(int idx, int w) {
	if (w == 3) return bfs();
	int ret = -1;
	for (int cur = idx + 1; cur < n * m; cur++) {
		int ci = cur / m, cj = cur % m;
		if (arr[ci][cj]) continue;
		arr[ci][cj] = 1;
		ret = max(ret, backtracking(cur, w + 1));
		arr[ci][cj] = 0;
	} return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
	cin >> n >> m;
	FOR(i, n) FOR(j, m) cin >> arr[i][j];
	cout << backtracking(-1, 0);
}