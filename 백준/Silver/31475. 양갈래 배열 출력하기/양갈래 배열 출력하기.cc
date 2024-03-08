#include <bits/stdc++.h>
using namespace std;

int r, c, mx, arr[2000][2000];
const int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

inline bool oob(int i, int j) { return (i < 0 || j < 0 || i >= r || j >= c); }
void solve(int i, int j, int dir, int dd) {
	if (dd == -1) {
		int ti = i, tj = j;
		while (!oob(ti, tj)) {
			arr[ti][tj] = 0;
			ti += di[dir], tj += dj[dir];
		}
	}

	for (int x = 1; x <= mx; ++x) {
		arr[i][j] = x;
		int ni = i + di[dir], nj = j + dj[dir];
		if (oob(ni, nj) || arr[ni][nj]) dir = (dir + 4 + dd) % 4;
		i += di[dir], j += dj[dir];
	}
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c;
	char ch; cin >> ch;

	if (ch == 'U') mx = r * (c>>1) + r, solve(0, c>>1, 1, 1), solve(0, c>>1, 1, -1);
	else if (ch == 'D') mx = r * (c>>1) + r, solve(r-1, c>>1, 3, 1), solve(r-1, c>>1, 3, -1);
	else if (ch == 'L') mx = c * (r>>1) + c, solve(r>>1, 0, 0, 1), solve(r>>1, 0, 0, -1);
	else mx = c * (r>>1) + c, solve(r>>1, c-1, 2, 1),solve(r>>1, c-1, 2, -1);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) cout << arr[i][j] << ' ';
		cout << '\n';
	}
}