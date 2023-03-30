#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int r, c, board[1500][1500];
int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };
string ice[1500];
vector<pii> swan;
bool visit[1500][1500];

inline bool oob(int i, int j) { return i < 0 || i >= r || j < 0 || j >= c; }

// x초 이내로 만날 수 있는가?
bool solve(int x) {
	for (int i = 0; i < r; i++) memset(visit[i], false, sizeof(bool) * c);
	queue<pii> q;
	q.push(swan[0]); visit[swan[0].X][swan[0].Y] = true;
	while (!q.empty()) {
		pii cur = q.front(); q.pop();

		if (cur == swan[1]) return true;
		for (int dir = 0; dir < 4; dir++) {
			int nxti = cur.X + di[dir], nxtj = cur.Y + dj[dir];

			if (oob(nxti, nxtj)) continue;
			if (visit[nxti][nxtj]) continue;
			if (board[nxti][nxtj] > x) continue;

			q.push({ nxti, nxtj }); visit[nxti][nxtj] = true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> ice[i];

	queue<pii> q;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (ice[i][j] == 'X') continue;
			if (ice[i][j] == 'L') swan.push_back({ i, j });
			q.push({ i, j }); visit[i][j] = true;
		}

	while (!q.empty()) {
		pii cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nxti = cur.X + di[dir], nxtj = cur.Y + dj[dir];
			
			if (oob(nxti, nxtj)) continue;
			if (visit[nxti][nxtj]) continue;

			if (ice[nxti][nxtj] == 'X') board[nxti][nxtj] = board[cur.X][cur.Y] + 1;
			q.push({ nxti, nxtj }); visit[nxti][nxtj] = true;
		}
	}

	int st = 0, en = 1500;
	while (st < en) {
		int mid = (st + en) / 2;

		if (solve(mid)) en = mid;
		else st = mid + 1;
	}
	cout << st;
}