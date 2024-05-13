#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
#define X first
#define Y second

int r, c, map[103][103], n, h;
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
bool l2r = true, visit[103][103];
queue<pii> q;

bool cutBlock(int h) {
	int sj = 0, d = 1;
	if (!l2r) {
		sj = c - 1;
		d = -1;
	}

	for (int j = sj; 0 <= j && j < c; j += d)
		if (map[h][j] == 1) {
			map[h][j] = 0;
			return true;
		}
	return false;
}
void search() {
	for (int i = 0; i < r; i++) fill(visit[i], visit[i]+c, false);
	
	for (int j = 0; j < c; j++) {
		if (map[r-1][j] == 1) {
			q.push({r-1, j}); visit[r-1][j] = true;
		}
	}

	while (!q.empty()) {
		pii cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			pii nxt = {cur.X + di[dir], cur.Y + dj[dir]};
			if (nxt.X < 0 || nxt.X >= r) continue;
			if (nxt.Y < 0 || nxt.Y >= c) continue;
			if (map[nxt.X][nxt.Y] == 0) continue;
			if (visit[nxt.X][nxt.Y]) continue;

			visit[nxt.X][nxt.Y] = true;
			q.push(nxt);
		}
	}
}
int canMove() {
	int ans = 999;
	for (int j = 0; j < c; j++) {
		for (int i = r-1; i >= 0; i--) {
			if (map[i][j] == 0) continue;
			if (visit[i][j]) continue;

			int d = 1;
			while (i+d < r && map[i+d][j] == 0) d++;

			ans = min(ans, d-1);
			break;
		}
	}
	return ans;
}
void move(int k) {
	for (int j = 0; j < c; j++) {
		for (int i = r-1; i >= 0; i--) {
			if (map[i][j] == 0) continue;
			if (visit[i][j]) continue;

			map[i][j] = 0;
			map[i+k][j] = 1;
		}
	}
}
void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j]) cout << 'x';
			else cout << '.';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str; cin >> str;
		for (int j = 0; j < c; j++)
			if (str.at(j) == 'x') map[i][j] = 1;
	}
	cin >> n;
	while (n--) {
		cin >> h;
		cutBlock(r - h);
		search();
		move(canMove());
		l2r = !l2r;
	}
	print();
}