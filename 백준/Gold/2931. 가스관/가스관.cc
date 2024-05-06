#include <bits/stdc++.h>
using namespace std;

int r, c, mi, mj, md;
string arr[25];
int vst[25][25];

const int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
string block_print = "01234|-+";

int nxt_dir_arr[8][4] = {
	{0,0,0,0},
	{-1, -1, 1, 0},
	{-1, 0, 3, -1},
	{3, 2, -1, -1},
	{1, -1, -1, 2},
	{-1, 1, -1, 3},
	{0, -1, 2, -1},
	{0, 1, 2, 3}
};

inline bool oob(int i, int j) {
	return i < 0 || j < 0 || i >= r || j >= c;
}

int start_dir() {
	for (int dir = 0; dir < 4; ++dir) {
		int ni = mi + di[dir], nj = mj + dj[dir];
		if (oob(ni, nj) || arr[ni][nj] == '.') continue;
		return dir;
	}
}

int nxt_dir(int cur_dir, char block_type) {
	switch (block_type)
	{
	case '|': return nxt_dir_arr[5][cur_dir];
	case '-': return nxt_dir_arr[6][cur_dir];
	case '+': return nxt_dir_arr[7][cur_dir];
	default: return nxt_dir_arr[block_type-'0'][cur_dir];
	}
}

void find_empty(int& blank_i, int& blank_j) {
	int i = mi, j = mj, dir = md;
	while (arr[i][j] != 'Z') {
		i += di[dir], j += dj[dir];
		
		// 이동한 결과가 빈칸 -> 타겟
		if (arr[i][j] == '.') {
			blank_i = i, blank_j = j;
			return;
		}

		dir = nxt_dir(dir, arr[i][j]);
	}
}

bool fill_block(int bi, int bj, int block) {
	memset(vst, 0, sizeof(vst));
	arr[bi][bj] = block_print[block];
	int i = mi, j = mj, dir = md;
	vst[i][j] = true;
	while (arr[i][j] != 'Z') {
		i += di[dir], j += dj[dir];

		if (oob(i, j) || arr[i][j] == '.') return false;
		++vst[i][j];

		dir = nxt_dir(dir, arr[i][j]);
		if (dir == -1) return false; 
	}

	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		if (arr[i][j] == '.' && vst[i][j]) return false;
		if (arr[i][j] == '+' && vst[i][j] != 2) return false;
		if (arr[i][j] != '.' && arr[i][j] != '+' && vst[i][j] != 1) return false;
	}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> r >> c;
	for (int i = 0; i < r; ++i) cin >> arr[i];

	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
		if (arr[i][j] == 'M') mi = i, mj = j;

	md = start_dir();

	int ti, tj;
	find_empty(ti, tj);

	for (int block = 1; block <= 7; ++block) {
		if (fill_block(ti, tj, block)) {
			cout << ti+1 << ' ' << tj+1 << ' ' << block_print[block];
			break;
		}
	}
}