#include <bits/stdc++.h>
using namespace std;

int r, c, t, board[50][50], up, down;
int di[4] = { 0, 1, 0, -1 }, dj[4] = {1, 0, -1, 0};

inline bool oob(int i, int j) { return (i < 0 || i >= r || j < 0 || j >= c); }
inline bool up_oob(int i, int j) { return (i < 0 || i > up || j < 0 || j >= c); }
inline bool down_oob(int i, int j) { return (i < down || i >= r || j < 0 || j >= c); }

void diffusion() {
	int temp[50][50] = { 0, };
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] <= 0) continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nxti = i + di[dir], nxtj = j + dj[dir];
				if (oob(nxti, nxtj) || board[nxti][nxtj] == -1) continue;
				temp[nxti][nxtj] += board[i][j] / 5;
				cnt++;
			}
			board[i][j] -= (board[i][j] / 5) * cnt;
		}
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			board[i][j] += temp[i][j];
}
void clean() {
	int dir = 3, curi = up - 1, curj = 0;
	while (true) {
		int nxti = curi + di[dir], nxtj = curj + dj[dir];
		while (up_oob(nxti, nxtj)) {
			dir = (dir + 1) % 4;
			nxti = curi + di[dir]; nxtj = curj + dj[dir];
		}
		if (nxti == up && nxtj == 0) break;
		board[curi][curj] = board[nxti][nxtj];
		board[nxti][nxtj] = 0;
		curi = nxti; curj = nxtj;
	}
	dir = 1, curi = down + 1, curj = 0;
	while (true) {
		int nxti = curi + di[dir], nxtj = curj + dj[dir];
		while (down_oob(nxti, nxtj)) {
			dir = (dir ? dir - 1 : 3);
			nxti = curi + di[dir]; nxtj = curj + dj[dir];
		}
		if (nxti == down && nxtj == 0) break;
		board[curi][curj] = board[nxti][nxtj];
		board[nxti][nxtj] = 0;
		curi = nxti; curj = nxtj;
	}
}
int ans() {
	int cnt = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (board[i][j] > 0) cnt += board[i][j];
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (!down && board[i][j] == -1) {
				up = i; down = i + 1;
			}
		}
	while (t--) {
		diffusion();
		clean();
	}
	cout << ans();
}