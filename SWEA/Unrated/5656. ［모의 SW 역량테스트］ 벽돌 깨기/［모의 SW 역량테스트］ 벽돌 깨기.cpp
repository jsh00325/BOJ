#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second
#define FOR(i, n) for(int (i) = 0; (i) < (n); (i)++)

const int MH = 17, MW = 12;
int n, w, h, ans = 0x7fffffff, origin[MH][MW], arr[MH][MW];
int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };
bool visit[MH][MW];

inline bool oob(int i, int j) { return i < 0 || i >= MH || j < 0 || j >= w; }
int simulation(int drop) {
	int st = 0, cnt = 0;
	while (!arr[st][drop] && st < MH) st++;
	if (st == MH) return cnt;
	memset(visit, false, sizeof(visit));

	// 터트리기
	queue<pii> q;
	q.push({ st, drop }); visit[st][drop] = true;
	while (!q.empty()) {
		pii cur = q.front(); q.pop(); cnt++;
		int p = arr[cur.X][cur.Y]; arr[cur.X][cur.Y] = 0;

		FOR(dir, 4) {
			int ni = cur.X, nj = cur.Y;
			FOR(d, p - 1) {
				ni += di[dir]; nj += dj[dir];
				if (oob(ni, nj)) break;
				if (arr[ni][nj] == 0) continue;
				if (visit[ni][nj]) continue;
				q.push({ ni, nj }); visit[ni][nj] = true;
			}
		}
	}

	// 구슬 내리기
	FOR(j, w) {
		int bottom = MH - 1;
		while (bottom >= 0 && arr[bottom][j]) bottom--;

		for (int i = bottom - 1; i >= 0; i--) {
			if (!arr[i][j]) continue;
			arr[bottom--][j] = arr[i][j];
			arr[i][j] = 0;
		}
	}
	return cnt;
}
int remain() {
	int cnt = 0;
	FOR(i, MH) FOR(j, MW) if (arr[i][j]) cnt++;
	return cnt;
}
int order[4];
void dfs(int cnt) {
	if (cnt == n) {
		if (ans == 0) return;
		FOR(i, MH) FOR(j, MW) arr[i][j] = origin[i][j];
		for (int i = 0; i < n; i++) simulation(order[i]);
		ans = min(ans, remain());
		return;
	}

	FOR(i, w) {
		order[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> w >> h;
		for (int i = MH - h; i < MH; i++) FOR(j, w) cin >> origin[i][j];
		dfs(0);

		cout << '#' << t << ' ' << ans << '\n';
		ans = 0x7fffffff; memset(origin, 0, sizeof(origin));
	}
	return 0;
}