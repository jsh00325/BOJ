#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n, m, wall[50][50], room[50][50], cnt = 1, ans;
int di[4] = { 0, -1, 0, 1 }, dj[4] = { -1, 0, 1, 0 };
bool visit[50][50];
vector<int> room_size(1);
inline bool oob(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> wall[i][j];

	queue<pii> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j]) continue;

			int sz = 0;
			q.push({ i, j }); visit[i][j] = true;
			while (!q.empty()) {
				pii cur = q.front(); q.pop();
				room[cur.X][cur.Y] = cnt;
				sz++;

				for (int dir = 0; dir < 4; dir++) {
					if (wall[cur.X][cur.Y] & (1 << dir)) continue;
					int ni = cur.X + di[dir], nj = cur.Y + dj[dir];
					if (visit[ni][nj]) continue;
					q.push({ ni, nj }); visit[ni][nj] = true;
				}
			}
			room_size.push_back(sz);
			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int dir = 2; dir < 4; dir++) {
				int ni = i + di[dir], nj = j + dj[dir];
				if (oob(ni, nj)) continue;
				if (room[i][j] == room[ni][nj]) continue;
				ans = max(ans, room_size[room[i][j]] + room_size[room[ni][nj]]);
			}
		}
	}
	cout << cnt - 1 << '\n' << *max_element(room_size.begin() + 1, room_size.end()) << '\n' << ans;
}