#include <iostream>
using namespace std;

int n, m, r, c, d, map[51][51], cnt;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	while (true) {
		if (map[r][c] == 0) {
			map[r][c]--;
			cnt++;
		}
		
		bool isOk = false;
		for (int turn = 3; turn >= 0; turn--) {
			int nowd = (d + turn) % 4;
			int newi = r + di[nowd];
			int newj = c + dj[nowd];
			
			if (newi < 0 || newi >= n) continue;
			if (newj < 0 || newj >= m) continue;
			if (map[newi][newj] != 0) continue;
			
			isOk = true;
			d = nowd;
			r = newi;
			c = newj;
			break;
		}
		if (!isOk) {
			if (map[r + di[(d + 2) % 4]][c + dj[(d + 2) % 4]] == 1) {
				cout << cnt;
				return 0;
			}
			else {
				r += di[(d + 2) % 4];
				c += dj[(d + 2) % 4];
			}
		}
	}
}