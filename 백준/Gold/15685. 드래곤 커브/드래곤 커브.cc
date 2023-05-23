#include <iostream>
using namespace std;

int n, x, y, d, g, rot[4][1050], map[111][111], cnt;
int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int di = 0; di < 4; di++) {
		rot[di][0] = di;
		for (int ge = 0; ge < 10; ge++) {
			for (int num = 0; num < (1 << ge); num++)
				rot[di][(1<<(ge+1))-num-1] = (rot[di][num] + 1) % 4;
		}
	}

	cin >> n;
	for (int p = 0; p < n; p++) {
		cin >> x >> y >> d >> g;
		map[y][x] = 1;
		for (int k = 0; k < (1 << g); k++) {
			y += di[rot[d][k]];
			x += dj[rot[d][k]];
			map[y][x] = 1;
		}
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1] == 4) cnt++;
		}
	}
	cout << cnt;
}