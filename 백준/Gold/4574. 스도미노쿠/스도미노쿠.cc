#include <bits/stdc++.h>
using namespace std;

#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR2(i, n) for (int (i) = 1; (i) <= (n); (i)++)

int n, u, v, tc, arr[10][10], di[2] = {0, 1}, dj[2] = {1, 0};
string lu, lv;
bool visit[10][10], get_arr;

void init() {
	MEM(arr, 0); MEM(visit, false);
	FOR2(i, 9) visit[i][i] = true;
	get_arr = false;
}
void set_cell(const string &cood, int val) {
	arr[cood[0] - 'A'][cood[1] - '1'] = val;
}
void print() {
	cout << "Puzzle " << tc << '\n';
	FOR(i, 9) {
		FOR(j, 9) cout << arr[i][j];
		cout << '\n';
	}
}
inline bool oob(int i, int j) { return i < 0 || i >= 9 || j < 0 || j >= 9; }
bool is_possible(int i, int j, int x) {
	FOR(nj, 9) if (arr[i][nj] == x) return false;
	FOR(ni, 9) if (arr[ni][j] == x) return false;
	int si = i / 3 * 3, sj = j / 3 * 3;
	FOR(di, 3) FOR(dj, 3) if (arr[si + di][sj + dj] == x) return false;
	return true;
}
void bt(int idx, int remain) {
	if (get_arr) return;
	while (idx < 81 && arr[idx / 9][idx % 9]) idx++;
	if (remain == 0) {
		print(); get_arr = true; return;
	}
	if (idx == 81) return;

	int i = idx / 9, j = idx % 9;
	FOR2(st, 9) FOR2(en, 9) {
		if (visit[st][en]) continue;
		if (!is_possible(i, j, st)) continue;

		FOR(dir, 2) {
			int ni = i + di[dir], nj = j + dj[dir];
			if (oob(ni, nj)) continue;
			if (arr[ni][nj]) continue;
			if (!is_possible(ni, nj, en)) continue;

			visit[st][en] = visit[en][st] = true;
			arr[i][j] = st; arr[ni][nj] = en;
			bt(idx + 1, remain - 2);
			visit[st][en] = visit[en][st] = false;
			arr[i][j] = 0; arr[ni][nj] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (tc = 1; ; tc++) {
		cin >> n; if (!n) break;
		init();
		for (int i = 0; i < n; i++) {
			cin >> u >> lu >> v >> lv;
			set_cell(lu, u); set_cell(lv, v);
			visit[u][v] = visit[v][u] = true;
		}
		for (int i = 1; i < 10; i++) {
			cin >> lu; set_cell(lu, i);
		}
		bt(0, 72 - 2 * n);
	}
}