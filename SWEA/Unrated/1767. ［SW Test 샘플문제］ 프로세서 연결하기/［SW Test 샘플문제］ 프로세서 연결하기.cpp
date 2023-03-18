#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second
#define FOR(i, n) for(int (i) = 0; (i) < (n); (i)++)

int n, ans_cnt, ans_len, arr[12][12];
int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };
vector<pii> core;

inline bool oob(int i, int j) { return i < 0 || i >= n || j < 0 || j >= n; }
int check(int i, int j, int dir) {
	int cnt = 0;
	i += di[dir]; j += dj[dir];
	while (!oob(i, j)) {
		if (arr[i][j]) return -1;
		i += di[dir]; j += dj[dir]; cnt++;
	}
	return cnt;
}
void fill(int i, int j, int dir, int val) {
	i += di[dir]; j += dj[dir];
	while (!oob(i, j)) {
		arr[i][j] = val;
		i += di[dir]; j += dj[dir];
	}
}
void solve(int idx, int cnt, int len) {
	if (idx == core.size()) {
		if (ans_cnt < cnt) (ans_cnt = cnt), (ans_len = len);
		else if (ans_cnt == cnt) ans_len = min(ans_len, len);
		return;
	}

	FOR(dir, 4) {
		pii& cur = core[idx];
		int w = check(cur.X, cur.Y, dir);
		if (w == -1) continue;
		fill(cur.X, cur.Y, dir, 1);
		solve(idx + 1, cnt + 1, len + w);
		fill(cur.X, cur.Y, dir, 0);
	}
	solve(idx + 1, cnt, len);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		FOR(i, n) FOR(j, n) {
			cin >> arr[i][j];
			if (!arr[i][j]) continue;
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
			core.push_back({ i, j });
		}
		solve(0, 0, 0);
		cout << '#' << t << ' ' << ans_len << '\n';
		ans_cnt = ans_len = 0; core.clear();
	}
	return 0;
}