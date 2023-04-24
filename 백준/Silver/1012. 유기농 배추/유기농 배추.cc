#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n, m, k, arr[50][50];
int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };
bool visit[50][50];
queue<pii> q;
bool oob(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		while (k--) {
			int x, y; cin >> x >> y;
			arr[x][y] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] || arr[i][j] == 0) continue;
				cnt++;
				q.push({ i, j }); visit[i][j] = true;
				while (!q.empty()) {
					pii cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int ni = cur.X + di[dir], nj = cur.Y + dj[dir];
						if (oob(ni, nj)) continue;
						if (arr[ni][nj] == 0) continue;
						if (visit[ni][nj]) continue;
						q.push({ ni, nj }); visit[ni][nj] = true;
					}
				}
			}
		}
		cout << cnt << '\n';

		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
	}
}