#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

const bool DEBUGGING = false;
int r, c, t;
int arr[50][50], diffuse_arr[50][50];

// 0, 1, 2, 3은 차례대로 위, 오른쪽, 아래, 왼쪽
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

/**	범위 밖을 벗어난다면 true 반환 */
inline bool oob(int i, int j) {
	return (i < 0 || i >= r || j < 0 || j >= c);
}

/** 공기의 흐름 범위 밖을 벗어난다면 true 반환
 * 	@param ti 공기청정기의 행 위치
 * 	@param tj 공기청정기의 열 위치
 * 	@param cw CW가 1이면 아래 범위, CW가 -1이면 윗 범위 */
bool oob_section(int ti, int tj, int i, int j, int cw) {
	if (cw == 1) return (i <= ti || i >= r || j < 0 || j >= c);
	else return (i < 0 || i > ti || j < 0 || j >= c);
}

/**	(i, j)의 위치에서 dir방향으로 이동하는 곳의 좌표 반환
 *  @param ti 공기청정기의 행 위치
 * 	@param tj 공기청정기의 열 위치
 * 	@param dir 참조형 변수를 통해 방향을 바꾸는 경우 바로 업데이트
 * 	@param cw ClockWise방향인지 확인 (-1: CCW, 1: CW) */
pii findNextCell(int ti, int tj, int i, int j, int& dir, int cw) {
	int ni = i + di[dir], nj = j + dj[dir];

	// 다음 셀에 접근하기 위해서는 방향을 바꿔야 하는 경우
	if (oob_section(ti, tj, ni, nj, cw)) {
		dir = (dir - cw + 4) % 4;
		ni = i + di[dir], nj = j + dj[dir];
	}

	return {ni, nj};
}

struct CLEANER {
	int ti, tj;	// 공기청정기의 위치 (2*1 중 위의 칸의 좌표)

	CLEANER() {
		// 모든 칸을 확인하면서 공기청정기의 위치 확인
		bool findFlag = false;
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
			if (!findFlag && arr[i][j] == -1) {
				ti = i, tj = j, findFlag = true;
			}
		}
	}

	/**	(i, j)를 기점으로 cw방향으로 공기를 순환시키는 내부 시뮬레이션 함수
	 * 	@param cw ClockWise방향인지 확인 (-1: CCW, 1: CW) */
	void _circulation(int i, int j, int cw) {
		/*
		바람 경로의 마지막에 있는 값은 사라지고 나머지는 한칸씩 밀린다
		경로를 평평하게 생각해 본다면
		1 2 3 4 5 6 7 8 9 -> 0 1 2 3 4 5 6 7 8 과 같이 진행된다.

		따라서 끝부분부터 한칸씩 밀면 되기 때문에, 끝 점에서 cw의 반대방향으로 돌면서 땡겨오자
		*/

		int si = i + (cw == 1 ? 1 : -1), sj = j, dir = (cw == 1 ? 2 : 0);
		
		while (true) {
			pii nxt = findNextCell(ti, tj, si, sj, dir, cw);

			if (arr[nxt.X][nxt.Y] == -1) {
				arr[si][sj] = 0;
				return;
			}

			arr[si][sj] = arr[nxt.X][nxt.Y];
			si = nxt.X, sj = nxt.Y;
		}
	}

	/**	공기청정기를 한번 가동했을 때의 결과를 시뮬레이션 */
	void blow() {
		_circulation(ti, tj, -1);
		_circulation(ti+1, tj, 1);
	}
};

/**	미세먼지의 확산을 시뮬레이션 하는 함수 */
void diffuse() {
	// 확산된 결과가 다른 칸에 영향을 끼치지 않도록, diffuse_arr에 저장
	memset(diffuse_arr, 0, sizeof(diffuse_arr));
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) if (arr[i][j] > 0){
		// 확산되는 양
		int diffuse_volume = arr[i][j] / 5;
		if (diffuse_volume == 0) continue;

		// 확산할 수 있는 방향 체크
		for (int dir = 0; dir < 4; ++dir) {
			int ni = i + di[dir], nj = j + dj[dir];
			if (oob(ni, nj) || arr[ni][nj] == -1) continue;

			// 확산이 가능한 경우 -> 해당 방향으로 확산
			arr[i][j] -= diffuse_volume, diffuse_arr[ni][nj] += diffuse_volume;
		}
	}

	// 확산된 결과를 저장
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
		arr[i][j] += diffuse_arr[i][j];
}

/**	방에 남아있는 미세먼지의 양을 찾는 함수
 * 	@return 미세먼지의 총합 반환 */
int remainDust() {
	int ret = 0;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		if (arr[i][j] > 0) ret += arr[i][j];
	}
	return ret;
}

void ForDebugging(int time) {
	if (!DEBUGGING) return;
	cout << "Time: " << time << "============\n";

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) cout << arr[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	// 입력
	cin >> r >> c >> t;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> arr[i][j];
	
	// 공기청정기 struct 생성 -> 생성자 함수 실행
	CLEANER purifier;

	ForDebugging(0);
	for (int time = 1; time <= t; ++time) {
		diffuse();
		ForDebugging(time);
		purifier.blow();
		ForDebugging(time);
	}
	cout << remainDust();	
}