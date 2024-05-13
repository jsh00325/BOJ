#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int r, c;
string arr[100];
bool vst[100][100];
const int di[4] = {0, -1, 0, 1}, dj[4] = {-1, 0, 1, 0};

inline bool oob(int i, int j) {
    return (i < 0 || j < 0 || i >= r || j >= c);
}

// h: 창이 날라온 높이, ori: 창이 날라오는 방향 (0: l->r, 1: r->l)
pii throwStick(int h, int ori) {
    int i = h, sj = (ori ? c-1 : 0), d = (ori ? -1 : 1);

    for (int j = sj; 0 <= j && j < c; j += d) {
        if (arr[i][j] == 'x') {
            arr[i][j] = '.';
            return {i, j};
        }
    } return {-1, -1};
}

// (i, j)가 포함된 클러스터가 얼마나 떨어질 수 있는지 확인
int calcDropHeight(int i, int j) {
    int drop_height = 0x7fffffff;

    // 열 단위로 떨어질 높이 계산
    for (int j = 0; j < c; ++j) {
        // 클러스터의 아래 블럭 찾기
        int bottom_i = -1;
        for (int i = 0; i < r; ++i) if (vst[i][j]) bottom_i = i;
        if (bottom_i == -1) continue;

        // 떨어질 높이 계산
        int cur_drop_height = r - bottom_i - 1;
        for (int delta = 1; bottom_i + delta < r; ++delta) {
            if (arr[bottom_i + delta][j] == '.') continue;
            cur_drop_height = delta - 1;
            break;
        }

        drop_height = min(drop_height, cur_drop_height);
    }
    return drop_height;
}

void dropCluster(int i, int j) {
    int drop_height = calcDropHeight(i, j);
    
    // 열 단위로 하나씩 이동시킴
    for (int j = 0; j < c; ++j) for (int i = r-1; i >= 0; --i) {
        if (!vst[i][j]) continue;   // droppableCluster가 아닌 경우

        arr[i][j] = '.';
        arr[i + drop_height][j] = 'x';
    }
}

// 떨어질 수 있는 클러스터인지 확인
//  -> 가장 낮은 블럭이 땅이 아니면 droppable
bool judgeDroppable(int i, int j) {
    memset(vst, false, sizeof(vst));
    int max_i = -1;

    queue<pii> q;
    q.push({i, j}); vst[i][j] = true;
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        max_i = max(max_i, cur.X);

        for (int dir = 0; dir < 4; ++dir) {
            int ni = cur.X + di[dir], nj = cur.Y + dj[dir];
            if (oob(ni, nj) || arr[ni][nj] == '.' || vst[ni][nj]) continue;

            q.push({ni, nj}); vst[ni][nj] = true;
        }
    }

    return (max_i != r-1);
}

// 부서진 블럭 근처에서 떨어질 수 있는 클러스터를 찾음
// 만약 있다면, 그 클러스터를 떨어뜨림
void searchDroppableCluster(pii broken_block) {
    for (int d = 0; d < 4; ++d) {
        int i = broken_block.X + di[d], j = broken_block.Y + dj[d];
        if (oob(i, j) || arr[i][j] == '.') continue;

        if (judgeDroppable(i, j)) {
            dropCluster(i, j);
            return;
        }
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    cin >> r >> c;
    for (int i = 0; i < r; ++i) cin >> arr[i];

    int q; cin >> q;
    for (int t = 0; t < q; ++t) {
        int h; cin >> h;

        // arr의 높이에 맞게 변형하여 throw
        pii broken_block = throwStick(r - h, t & 1);
        if (broken_block == pii{-1, -1}) continue;

        // 떨어질 수 있는 클러스터를 찾아보기
        searchDroppableCluster(broken_block);
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) cout << arr[i][j];
        cout << '\n';
    }
}