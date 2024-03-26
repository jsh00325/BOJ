#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;
typedef long long ll;

struct Taxi {
	int i, j, fuel;
} taxi;

struct Passenger {
	int i, j;	// 현재 위치
	int gi, gj; // 목적지의 좌표
	bool isEnd; // 승객이 목적지에 도착했는지
} passenger[400];

const int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
int n, m, arr[22][22], vst[22][22];

/**	승객이 목적지까지의 거리를 구하는 함수
 * 	@param p 구하고자 하는 승객의 참조형 변수
 * 	@return 승객 p의 목적지 거리 */
int calculateDist(Passenger& p) {
	// 초기화 (vst는 방문체크를 위해서 -1로 초기화)
	queue<pii> q; memset(vst, -1, sizeof(vst));

	// vst에는 (p.i, p.j)에서 부터의 최단거리가 저장됨
	q.push({p.i, p.j}); vst[p.i][p.j] = 0;
	while (!q.empty()) {
		pii cur = q.front(); q.pop();

		// 현재 위치가 목적지인 경우
		if (cur.X == p.gi && cur.Y == p.gj)
			return vst[cur.X][cur.Y];

		// 4방향 탐색
		for (int dir = 0; dir < 4; ++dir) {
			int ni = cur.X + di[dir], nj = cur.Y + dj[dir];

			// 벽이거나 이미 방문한 경우
			if (arr[ni][nj] == 1 || vst[ni][nj] != -1) continue;

			q.push({ni, nj}); vst[ni][nj] = vst[cur.X][cur.Y] + 1;
		}
	}
	return -1;
}

/**	승객 a가 승객 b보다 우선순위가 높은지(가장 위, 가장 좌측) 판단하는 함수 */
bool isFront(Passenger& a, Passenger& b) {
	if (a.i == b.i) return a.j < b.j;
	else return a.i < b.i;
}

/**	택시가 조건을 만족하는 승객을 찾는 함수
 * 	@return 승객의 Id (조건을 만족하는 승객이 없다면 -1 반환) */
int findPassenger() {
	// calculateDist()함수와 같은 방식으로 BFS -> 모든 곳의 거리를 구해놓기
	queue<pii> q; memset(vst, -1, sizeof(vst));
	
	q.push({taxi.i, taxi.j}); vst[taxi.i][taxi.j] = 0;
	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int ni = cur.X + di[dir], nj = cur.Y + dj[dir];
			if (arr[ni][nj] == 1 || vst[ni][nj] != -1) continue;

			q.push({ni, nj}); vst[ni][nj] = vst[cur.X][cur.Y] + 1;
		}
	}

	// 모든 승객과의 거리 중 조건을 만족하는 승객 찾기
	int minDist = 0x7fffffff, minPID = -1;
	for (int i = 0; i < m; ++i) {
		Passenger& cur = passenger[i];
		if (cur.isEnd) continue;

		// 현재 승객과 택시 사이의 거리
		int curDist = vst[cur.i][cur.j];
		if (curDist == -1) continue;

		if (minDist > curDist) minDist = curDist, minPID = i;
		else if (minDist == curDist && isFront(cur, passenger[minPID])) minPID = i;
	}
	return minPID;
}

/**	승객 p를 도착지로 움직이는 함수
 * 	@details 	1. 택시를 승객의 위치로 이동
 * 				2. 승객을 목적지로 이동
 * 				3-1. (1)~(2)수행 중 연료가 부족하지 않다면, 연료 충전 후 true반환
 * 				3-2. (1)~(2)수행 중 연료가 부족하다면 false반환
 * 	@return 승객이 이동할 수 있는지 여부를 반환 */
bool movePassenger(Passenger& p) {
	int taxi_to_passenger_dist = vst[p.i][p.j];
	int passenger_to_goal_dist = calculateDist(p);

	// 승객을 목적지로 이동시킬 수 없는 경우
	if (passenger_to_goal_dist == -1) return false;

	// 목적지까지 이동하기 위한 연료가 부족한 경우
	if (taxi_to_passenger_dist + passenger_to_goal_dist > taxi.fuel) return false;

	// 승객을 목적지로 이동 후 도착 처리
	taxi.i = p.gi;
	taxi.j = p.gj;
	p.isEnd = true;

	// 조건에 따라 연료 사용 후 충전
	taxi.fuel -= taxi_to_passenger_dist;
	taxi.fuel += passenger_to_goal_dist;

	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// 입력
	cin >> n >> m >> taxi.fuel;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) 
			cin >> arr[i][j];

	// 	지도의 주변을 벽으로 둘러서 Out Of Bound 처리 안하기
	for (int i = 1; i <= n; ++i) arr[i][0] = arr[i][n+1] = 1;
	for (int j = 0; j <= n+1; ++j) arr[0][j] = arr[n+1][j] = 1;

	cin >> taxi.i >> taxi.j;
	
	for (int i = 0; i < m; ++i) {
		Passenger& cur = passenger[i];
		cin >> cur.i >> cur.j >> cur.gi >> cur.gj;
	}

	int completeCount = 0;

	// 시뮬레이션 시작
	while (completeCount < m) {
		int targetPassenger = findPassenger();
		if (targetPassenger == -1) break;

		// 해당 승객이 이동 중 연료가 부족한 경우
		if (!movePassenger(passenger[targetPassenger])) break;

		// 해당 승객이 이동에 성공한 경우
		++completeCount;
	}

	if (completeCount == m) cout << taxi.fuel;
	else cout << -1;	
}