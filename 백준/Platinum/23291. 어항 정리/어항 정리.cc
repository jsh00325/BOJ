#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); ++(i))

const int MX = 100;
int n, k, t, arr[MX + 1][MX + 1], temp[MX+1][MX+1];
int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };

void plus_min_one() {
	int minVal = 0x7fffffff;
	FOR(i, n) minVal = min(minVal, arr[MX][i]);
	FOR(i, n) if (arr[MX][i] == minVal) arr[MX][i]++;
}
int getHeight(int j) { FOR(i, n) if (arr[MX - i][j] == 0) return i; }
void move1() {
	int cj1 = 0, cj2 = 0, ch = getHeight(cj1);
	while ((n - 1 - cj2) >= ch) {
		FOR1(dj, cj2 - cj1 + 1) FOR(di, ch)
			arr[MX - dj][cj2 + di + 1] = arr[MX - di][cj2 - dj + 1],
			arr[MX - di][cj2 - dj + 1] = 0;
		cj1 = cj2 + 1; cj2 = cj1 + ch - 1; ch = getHeight(cj1);
	}
}
inline bool oob(int i, int j) { return i < 0 || i > MX || j < 0 || j > MX; }
void adjust() {
	MEM(temp, 0);
	FOR(i, MX + 1) FOR(j, MX + 1) if (arr[i][j]) {
		FOR(dir, 4) {
			int ni = i + di[dir], nj = j + dj[dir];
			if (oob(ni, nj)) continue;
			if (arr[i][j] > arr[ni][nj]) continue;
			int d = (arr[ni][nj] - arr[i][j]) / 5;
			temp[ni][nj] -= d; temp[i][j] += d;
		}
	}
	FOR(i, MX + 1) FOR(j, MX + 1) arr[i][j] += temp[i][j];
}
void lay_down() {
	int nj = 0, tp = 0;
	FOR(j, n) if (arr[MX][j])
		for (int ci = MX; arr[ci][j]; ci--)
			tp = arr[ci][j], arr[ci][j] = 0, arr[MX][nj++] = tp;
}
void move2() {
	int nj = n; FOR(j, n / 2) arr[MX - 1][--nj] = arr[MX][j], arr[MX][j] = 0;
	nj = n; FOR(dj, n / 4) arr[MX - 2][--nj] = arr[MX - 1][n / 2 + dj], arr[MX - 1][n / 2 + dj] = 0;
	nj = n; FOR(dj, n / 4) arr[MX - 3][--nj] = arr[MX][n / 2 + dj], arr[MX][n / 2 + dj] = 0;
}

void simulation() {
	plus_min_one();
	move1(); adjust();
	lay_down();
	move2(); adjust();
	lay_down();
}
bool check() {
	int maxVal = -1, minVal = 0x7fffffff;
	FOR(i, n) minVal = min(minVal, arr[MX][i]), maxVal = max(maxVal, arr[MX][i]);
	return (maxVal - minVal) <= k;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k; FOR(i, n) cin >> arr[MX][i];
	while (!check()) {
		simulation(); t++;
	} cout << t;
}