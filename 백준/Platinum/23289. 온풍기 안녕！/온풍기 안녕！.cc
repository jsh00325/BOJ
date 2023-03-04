#include <bits/stdc++.h>
using namespace std;

struct room { int x, y; };
struct heat { int x, y, dir; };
int r, c, k, w, arr[23][23], plus_tp[23][23];
bool sero[23][23], garo[23][23], visit[23][23];
vector<room> checklist;
vector<heat> heater;

inline bool oob(int i, int j) { return i < 0 || i >= r || j < 0 || j >= c; }
int nxti[4][3] = { {-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1} };
int nxtj[4][3] = { {1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1} };
int di[4] = { 0, 0, -1, 1 }, dj[4] = { 1, -1, 0, 0 };

// 바뀐 온도 정보 저장하기
void sync() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] += plus_tp[i][j];
			plus_tp[i][j] = 0;
		}
	}
}
// 시작점의 좌표와 방향이 주어졌을 때 벽이 있는지 확인
bool isWall(int i, int j, int dir, int nd) {
	if (dir == 0) {
		if (nd == 0) return garo[i - 1][j] || sero[i - 1][j];
		if (nd == 1) return sero[i][j];
		if (nd == 2) return garo[i][j] || sero[i + 1][j];
	}
	else if (dir == 1) {
		if (nd == 0) return sero[i - 1][j - 1] || garo[i - 1][j];
		if (nd == 1) return sero[i][j - 1];
		if (nd == 2) return sero[i + 1][j - 1] || garo[i][j];
	}
	else if (dir == 2) {
		if (nd == 0) return garo[i - 1][j - 1] || sero[i][j - 1];
		if (nd == 1) return garo[i - 1][j];
		if (nd == 2) return garo[i - 1][j + 1] || sero[i][j];
	}
	else if (dir == 3) {
		if (nd == 0) return garo[i][j - 1] || sero[i][j - 1];
		if (nd == 1) return garo[i][j];
		if (nd == 2) return garo[i][j + 1] || sero[i][j];
	}
}
// 온풍기 바람 부는것 구현하는 재귀함수
void blow_rec(int i, int j, int dir, int s) {
	plus_tp[i][j] += s;

	if (s == 1) return;
	for (int nd = 0; nd < 3; nd++) {
		int ni = i + nxti[dir][nd], nj = j + nxtj[dir][nd];
		if (oob(ni, nj)) continue;
		if (visit[ni][nj]) continue;
		if (isWall(i, j, dir, nd)) continue;
		
		visit[ni][nj] = true;
		blow_rec(ni, nj, dir, s - 1);
	}
}
// 온풍기 바람 불기
void blow(int i, int j, int dir) {
	memset(visit, false, sizeof(visit));
	blow_rec(i + di[dir], j + dj[dir], dir, 5);
}
// 온도 조절하기
void tp_adj() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c - 1; j++) {
			// (i, j) - (i, j+1) 조절
			if (sero[i][j]) continue;
			int gap = abs(arr[i][j] - arr[i][j + 1]) / 4;
			if (arr[i][j] > arr[i][j + 1]) {
				plus_tp[i][j] -= gap;
				plus_tp[i][j + 1] += gap;
			}
			else {
				plus_tp[i][j] += gap;
				plus_tp[i][j + 1] -= gap;
			}
		}
	}
	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < c; j++) {
			// (i, j) - (i+1, j) 조절
			if (garo[i][j]) continue;
			int gap = abs(arr[i][j] - arr[i + 1][j]) / 4;
			if (arr[i][j] > arr[i + 1][j]) {
				plus_tp[i][j] -= gap;
				plus_tp[i + 1][j] += gap;
			}
			else {
				plus_tp[i][j] += gap;
				plus_tp[i + 1][j] -= gap;
			}
		}
	}
	sync();
}
// 가장자리 온도 1씩 낮추기
void cooling() {
	for (int i = 0; i < r; i++) {
		if (arr[i][0]) arr[i][0]--;
		if (arr[i][c-1]) arr[i][c-1]--;
	}
	for (int j = 1; j < c - 1; j++) {
		if (arr[0][j]) arr[0][j]--;
		if (arr[r - 1][j]) arr[r - 1][j]--;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int temp; cin >> temp;
			if (1 <= temp && temp <= 4) heater.push_back({ i, j, temp - 1 });
			else if (temp == 5) checklist.push_back({ i, j });
		}
	}
	cin >> w;
	while (w--) {
		int x, y, t; cin >> x >> y >> t;
		if (t == 0) garo[x - 2][y - 1] = true;
		else sero[x - 1][y - 1] = true;
	}

	int turn = 1;
	for (turn; turn <= 100; turn++) {
		for (heat h : heater) blow(h.x, h.y, h.dir);
		sync();
		tp_adj();
		cooling();

		bool is_end = true;
		for (room rm : checklist)
			if (arr[rm.x][rm.y] < k) is_end = false;
		if (is_end) break;
	}
	cout << turn;
}