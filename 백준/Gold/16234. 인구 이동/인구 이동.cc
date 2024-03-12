#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int n, l, r;
vector<vector<int>> population_info;
bool vst[50][50];


/**	(i, j)가 주어진 입력의 범위를 넘아가는지 확인하는 inline 함수
 * 	@return 범위 바깥이라면 true, 범위 내의 영역이면 false */
inline bool oob(int i, int j) {
	return i < 0 || j < 0 || i >= n || j >= n;
}

/** bfs를 통해서 인구 이동을 수행하는 함수
 *	@return 인구이동이 일어난다면 true, 일어나지 않는다면 false */
bool move_population() {
	// 초기화
	memset(vst, 0, sizeof(vst));
	bool isMoved = false;

	// 모든 칸을 돌면서 인구이동이 가능한지를 확인
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (vst[i][j]) continue;

		queue<pii> q;
		vector<pii> sameArea;
		int area_sum = 0;
		q.push({i, j}); vst[i][j] = true;

		while (!q.empty()) {
			pii cur = q.front(); q.pop();

			area_sum += population_info[cur.X][cur.Y];
			sameArea.push_back(cur);

			int& cur_population = population_info[cur.X][cur.Y];

			for (int dir = 0; dir < 4; ++dir) {
				int ni = cur.X + ("0211"[dir]-'1'), nj = cur.Y + ("1102"[dir]-'1');
				if (oob(ni, nj) || vst[ni][nj]) continue;
				
				int diff = abs(cur_population - population_info[ni][nj]);
				if (diff < l || r < diff) continue;

				q.push({ni, nj}); vst[ni][nj] = true;
			}
		}

		// 인구이동이 일어나는 경우
		if (sameArea.size() > 1) {
			int final_population = area_sum / sameArea.size();

			for (auto& cur : sameArea)
				population_info[cur.X][cur.Y] = final_population;
			
			isMoved = true;
		}
	}
	return isMoved;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// 입출력
	cin >> n >> l >> r;
	population_info.resize(n);
	for (auto& i : population_info) {
		i.resize(n);
		for (auto& j : i) cin >> j;
	}

	for (int days = 0; ; ++days) {
		if (move_population()) continue;
		cout << days;
		break;
	}
}