#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, l, r, rslt;
int map[53][53];
bool visit[53][53];
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	while(true) {
		for (int i = 0; i < 53; i++) fill(visit[i], visit[i]+53, false);
		bool isRun = false;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j]) continue;
				queue<pair<int, int>> q, temp;

				int sum = 0;
				
				q.push({i, j});
				temp.push({i, j});
				visit[i][j] = true;

				while (!q.empty()) {
					int nowi = q.front().first;
					int nowj = q.front().second;
					sum += map[nowi][nowj];
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int newi = nowi + di[dir];
						int newj = nowj + dj[dir];

						if (newi < 0 || newi >= n) continue;
						if (newj < 0 || newj >= n) continue;
						if (visit[newi][newj]) continue;

						int gap = abs(map[nowi][nowj] - map[newi][newj]);

						if (!(l <= gap && gap <= r)) continue;

						q.push({newi, newj});
						temp.push({newi, newj});
						visit[newi][newj] = true;
					}
				}

				if (temp.size() > 1) {
					isRun = true;
					sum /= temp.size();

					while(!temp.empty()) {
						map[temp.front().first][temp.front().second] = sum;
						temp.pop();
					}
				}
			}
		}
		if (isRun) rslt++;
		else break;
	}
	cout << rslt;
}