#include <bits/stdc++.h>
using namespace std;

struct Magic { int d, s; };
struct BallGroup { int type, cnt; };

const int set_di[4] = {1, 0, -1, 0}, set_dj[4] = {0, 1, 0, -1};
const int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};
int n, m, arr[49][49], flat_idx[49][49], flat[2500], ans[4];

/** 평탄화했기 때문에 마법 사용 시 적용되는 구슬의 위치를 알아야 함.
 * 	-> 각 셀이 평탄화 된 배열에서의 인덱스가 무엇인지 flat_idx에 저장
 * 	@param i, j 처음 상어의 좌표
 * 	@param step 중심을 기준으로 몇바퀴 돌아야 하는지 */
void setCellNum(int i, int j, int step) {
	int cur_idx = 0;
	for (int move_limit = 2; move_limit <= 2*step; move_limit += 2) {
		--i, --j;

		for (int dir = 0; dir < 4; ++dir) {
			for (int move = 0; move < move_limit; ++move) {
				i += set_di[dir], j += set_dj[dir];
				flat_idx[i][j] = cur_idx++;
			}
		}
	}
}

/**	입력으로 주어진 2차원 배열을 경로에 따라 평탄화 */
void flatten() {
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (arr[i][j]) flat[flat_idx[i][j]] = arr[i][j];
	}
}

/** 시뮬레이션 시작 전, 정보를 전처리하는 함수 */
void init() {
	setCellNum(n>>1, n>>1, n>>1);
	flatten();
}

/** 마법 정보에 따라 구슬을 삭제하는 함수
 * 	@param d 마법을 사용할 방향 (0-idx로 넣기)
 * 	@param s 마법의 세기 */
void removeBall(int d, int s) {
	int i = n >> 1, j = n >> 1;
	for (int move = 0; move < s; ++move) {
		i += di[d], j += dj[d];
		flat[flat_idx[i][j]] = 0;
	}
}

/**	같은 구슬끼리 합쳐서 그룹을 만들어서 관리
 * 	@param v 구슬 그룹을 보관할 벡터의 참조형 변수 */
void mergeBall(vector<BallGroup>& v) {
	for (int i = 0; i < n*n - 1; ++i) {
		// 해당 칸에 공이 없으면 pass
		if (!flat[i]) continue;

		// 그룹이 없어서 합칠 수 없는 경우
		if (v.empty()) v.push_back({flat[i], 1});
		// 앞의 그룹과 번호가 달라서 합칠 수 없는 경우
		else if (v.end()[-1].type != flat[i]) v.push_back({flat[i], 1});
		// 앞의 그룹과 번호가 같아 합치는 경우
		else ++v.end()[-1].cnt;
	}
}

/** 벡터를 순회하면서 터질 수 있는 그룹은 터트리는 함수 
 * 	@param v 구슬 그룹이 보관된 벡터의 참조형 변수
 * 	@return 구슬 폭발이 있었는지 여부를 반환 */
bool isExplode(vector<BallGroup>& v) {
	bool removeFlag = false;

	// 지울 인덱스를 벡터에 저장
	vector<bool> is_removed(v.size());
	for (int i = 0; i < v.size(); ++i) if (v[i].cnt >= 4) {
		is_removed[i] = true;
		ans[v[i].type] += v[i].cnt;
		removeFlag = true;
	}
	if (!removeFlag) return false;

	// 그룹을 지운 이후 남은 그룹을 밀어서 합치는 과정
	vector<BallGroup> new_v;
	for (int i = 0; i < v.size(); ++i) {
		if (is_removed[i]) continue;

		if (new_v.empty()) new_v.push_back(v[i]);
		else if (new_v.end()[-1].type != v[i].type) new_v.push_back(v[i]);
		else new_v.end()[-1].cnt += v[i].cnt;		
	}

	v = new_v;
	return true;
}

/**	폭발할 수 있는 구슬을 터트리는 함수
 * 	@param v 구슬 그룹이 보관된 벡터의 참조형 변수 */
void explodeBall(vector<BallGroup>& v) {
	// 터질 수 있다면? 계속 반복
	while (isExplode(v)) { }
}

/**	폭발 이후 규칙에 따라 변화하는 함수
 * 	@details 벡터에 저장된 구슬그룹이 flat으로 들어감
 * 	@param v 구슬 그룹이 보관된 벡터의 참조형 변수 */
void changeBall(vector<BallGroup>& v) {
	// 조건에 맞추어 그룹에서 count, type순으로 flat배열에 넣음
	memset(flat, 0, sizeof(flat));
	for (int i = 0; i < n*n - 1 && (i>>1) < v.size(); i += 2) {
		flat[i] = v[i>>1].cnt;
		flat[i+1] = v[i>>1].type;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];

	vector<Magic> magic(m);
	for (auto& i : magic) cin >> i.d >> i.s;

	init();

	int t = 0;
	// 시뮬레이션 시작
	for (auto& ma : magic) {
		removeBall(ma.d - 1, ma.s);

		vector<BallGroup> ball_group_vector;
		mergeBall(ball_group_vector);

		explodeBall(ball_group_vector);

		changeBall(ball_group_vector);
	}
    
	cout << ans[1] + 2*ans[2] + 3*ans[3];
}