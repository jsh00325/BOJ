#include <bits/stdc++.h>
using namespace std;

const int di[8] = {0,-1,-1,-1,0,1,1,1}, dj[8] = {-1,-1,0,1,1,1,0,-1};
const int ddi[4] = {-1, -1, 1, 1}, ddj[4] = {-1, 1, -1, 1};
int n, m, arr[50][50];
bool cloud[50][50], temp[50][50];

/** 시뮬레이션 전, 좌측 구석에 구름 만들기 */
void init_cloud() {
	cloud[n-1][0] = cloud[n-1][1] = cloud[n-2][0] = cloud[n-2][1] = true;
}

/** 범위를 벗어나는지 체크하는 함수 */
inline bool oob(int i, int j) {
	return i < 0 || j < 0 || i >= n || j >= n;
}

/**	1. 현재 존재하는 구름을 d방향으로 s만큼 이동시키는 함수
 * 	@param d 방향을 0-idx 형식으로 입력 */
void move_cloud(int d, int s) {
	memset(temp, 0, sizeof(temp));

	// 구름이 있는 칸 -> temp에 주어진 정보만큼 이동
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (cloud[i][j]) {
		// 끝과 끝이 연결되어 있기 때문에, % n을 통해서 조정
		int ni = (i + n*s + s*di[d]) % n, nj = (j + n*s + s*dj[d]) % n;

		temp[ni][nj] = true;
	}

	// temp에 기록된 값 적용
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		cloud[i][j] = temp[i][j];
}

/**	2. 구름 정보에 따라서 비를 내리고
 * 	3. 구름을 없애는 함수
 * 	@details 이후 5번 연산을 위해 현재 구름 정보는 temp */
void drop_rain() {
	// 비내리기
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		if (cloud[i][j]) ++arr[i][j];
	
	// temp에 현재 구름 정보가 저장되어 있음 (move_cloud에서 저장)

	// 구름 없애기
	memset(cloud, 0, sizeof(cloud));
}

/**	4. 비가 온 칸에 물복사버그를 시전하는 함수
 * 	@details temp에 저장된 칸이 비가 온 칸임을 이용 */
void copy_water() {
	// 이번 단계에서 증가하는 물의 양 저장
	int added_water[50][50] = {0, };

	// 비가 온 칸에 한해서 물복사 버그 진행
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (temp[i][j]) {
		for (int dir = 0; dir < 4; ++dir) {
			int ni = i + ddi[dir], nj = j + ddj[dir];
			if (oob(ni, nj) || arr[ni][nj] == 0) continue;
			++added_water[i][j];
		}
	}

	// 실제로 물을 증가시킴
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		arr[i][j] += added_water[i][j];
}

/**	5. 물의 양이 2 이상인 칸에 구름 생성 후, 물을 2만큼 줄임 */
void make_cloud() {
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		// 물이 2 미만인 경우 -> pass
		if (arr[i][j] < 2) continue;

		// 3에서 구름이 사라진 칸인 경우 -> pass
		if (temp[i][j]) continue;

		cloud[i][j] = true;
		arr[i][j] -= 2;
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		cin >> arr[i][j];

	init_cloud();

	// 시뮬레이션 시작
	for (int time = 1; time <= m; ++time) {
		int d, s; cin >> d >> s;

		move_cloud(d-1, s);
		drop_rain();
		copy_water();
		make_cloud();
	}

	// 남은 물의 수 계산
	int remain = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		remain += arr[i][j];
	cout << remain;	
}