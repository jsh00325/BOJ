#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

int n, map[23][23], shark_i, shark_j, shark_size, eat, result;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9)	{
				shark_size = 2;
				eat = 0;
				shark_i = i;
				shark_j = j;
			}
		}
	}
	
	while (true) {
		// 먹을 수 있는 물고기 찾기 -> bfs로 찾아내기
		queue<tuple<int, int, int>> q;
		bool visit[23][23] = {0, };
		int minDist = 999;
		int target_i = 999, target_j = 999;

		q.push({shark_i, shark_j, 0});
		visit[shark_i][shark_j] = true;
		while (!q.empty()) {
			int nowi, nowj, dist;
			tie(nowi, nowj, dist) = q.front();
			q.pop();

			if (minDist != 999 && dist == minDist) {
				if (map[nowi][nowj] != 0 && map[nowi][nowj] < shark_size) {
					// 먹을 수 있는 물고기임 => 타겟에 비교하고 저장하기.
					if (nowi < target_i) {
						target_i = nowi;
						target_j = nowj;
					}
					else if (nowi == target_i) {
						if (nowj < target_j) {
							target_i = nowi;
							target_j = nowj;
						}
					}
				}
				continue;
			}

			for (int dir = 0; dir < 4; dir++) {
				int newi = nowi + di[dir];
				int newj = nowj + dj[dir];

				if (newi < 0 || newi >= n || newj < 0 || newj >= n) continue;
				if (map[newi][newj] > shark_size) continue;
				if (visit[newi][newj]) continue;

				if (map[newi][newj] != 0 && map[newi][newj] < shark_size) minDist = dist+1;
				q.push({newi, newj, dist+1});
				visit[newi][newj] = true;
			}
		}

		if (target_i == 999 && target_j == 999) break; // 먹을 물고기가 없는 경우
		else {
			map[shark_i][shark_j] = 0;
			result += minDist;
			shark_i = target_i;
			shark_j = target_j;

			map[shark_i][shark_j] = 9;

			if (++eat == shark_size) {
				shark_size++;
				eat = 0;
			} 
		}
	}
	cout << result;	
}