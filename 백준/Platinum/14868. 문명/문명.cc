#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

const int MAX = 2000;
int n, k, arr[MAX][MAX], p[MAX*MAX];
int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };
bool visit[MAX][MAX];
typedef struct {
	int x, y, d;
} Node;
queue<Node> q;

inline int convert2D(int i, int j) { return i * n + j; }
inline bool oob(int i, int j) { return i < 0 || j < 0 || i >= n || j >= n; }

int find(int x) {
	if (p[x] < 0) return x;
	else return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return false;
	if (p[x] < p[y]) (p[x] += p[y]), (p[y] = x);
	else (p[y] += p[x]), (p[x] = y);
	return true;
}
int merge_around(int x, int y) {
	int merge_cnt = 0;
	FOR(dir, 4) {
		int ni = x + di[dir], nj = y + dj[dir];
		if (oob(ni, nj)) continue;
		if (visit[ni][nj]) merge_cnt += merge(convert2D(x, y), convert2D(ni, nj));
	} return merge_cnt;
}
int solve() {
	if (k == 1) return 0;
	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		FOR(dir, 4) {
			int ni = cur.x + di[dir], nj = cur.y + dj[dir];
			if (oob(ni, nj)) continue;

			if (visit[ni][nj]) k -= merge(convert2D(cur.x, cur.y), convert2D(ni, nj));
			else {
				merge(convert2D(cur.x, cur.y), convert2D(ni, nj));
				k -= merge_around(ni, nj);
				q.push({ ni, nj, cur.d + 1 }); visit[ni][nj] = true;
			}
			if (k == 1) return cur.d + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	FOR(i, n*n) p[i] = -1;
	int temp = 0;
	FOR(i, k) {
		int x, y; cin >> x >> y;
		q.push({ x - 1, y - 1, 0 }); visit[x - 1][y - 1] = true;
		temp += merge_around(x - 1, y - 1);
	} k -= temp;
	cout << solve();
}