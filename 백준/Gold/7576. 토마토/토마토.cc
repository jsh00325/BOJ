#include <bits/stdc++.h>
using namespace std;

const int MX = 1003;
int arr[MX][MX];
typedef struct { int r, c; } node;

inline bool oob(int m, int n, node &a) {
	return (a.r < 0 || a.r >= n || a.c < 0 || a.c >= m);
}

int solve(int m, int n) {
	int mx = -1;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (arr[i][j] == 0) return -1;
		mx = max(mx, arr[i][j]);
	}
	return mx - 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	queue<node> q;
	int m, n; cin >> m >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		int &cur = arr[i][j]; cin >> cur;
		if (cur == 1) q.push({i, j});
	}

	while (!q.empty()) {
		node cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			node nxt = { cur.r + ("1012"[dir] - '1'), cur.c + ("0121"[dir] - '1') };
			if (oob(m, n, nxt)) continue;
			if (arr[nxt.r][nxt.c]) continue;
			arr[nxt.r][nxt.c] = arr[cur.r][cur.c] + 1;
			q.push(nxt);
		}
	}

	cout << solve(m, n);
}