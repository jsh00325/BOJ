#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); ++(i))
typedef struct { int x, y; } node;

const int INF = 0x7fffffff;
int r, c, n, h;
int di[4] = { 0, 0, -1, 1 }, dj[4] = { 1, -1, 0, 0 };
bool visit[100][100];
string arr[100];

// dir = 0 : 왼쪽에서	dir = 1 : 오른쪽에서
int cutBlock(int i, int dir) {
	string &cur = arr[i];
	if (dir) { for (int j = c - 1; j >= 0; --j) if (cur[j] == 'x') { cur[j] = '.'; return j; } }
	else { for (int j = 0; j < c; ++j) if (arr[i][j] == 'x') { cur[j] = '.'; return j; } }
	return -1;
}
inline bool oob(int i, int j) {return i < 0 || i >= r || j < 0 || j >= c;}
bool cmp(const node& a, const node& b) { return a.y == b.y ? a.x > b.x : a.y < b.y; }
vector<node> getCluster(int i, int j) {
	vector<node> cluster;
	queue<node> q; MEM(visit, false);
	q.push({ i, j }); visit[i][j] = true;
	while (!q.empty()) {
		node cur = q.front(); q.pop();
		cluster.push_back(cur);
		FOR(dir, 4) {
			int ni = cur.x + di[dir], nj = cur.y + dj[dir];
			if (oob(ni, nj)) continue;
			if (arr[ni][nj] == '.') continue;
			if (visit[ni][nj]) continue;
			q.push({ ni, nj }); visit[ni][nj] = true;
		}
	}
	sort(cluster.begin(), cluster.end(), cmp);
	return cluster;
}
bool isCluster(const vector<node> &cluster) {
	for (auto &cur : cluster) if (cur.x == r - 1) return false;
	return true;
}
int getMoveDist(const vector<node>& cluster) {
	int ret = INF;
	for (auto& cur : cluster) {
		int dist = r - cur.x - 1;
		for (int i = cur.x + 1; i < r; ++i) {
			if (visit[i][cur.y]) { dist = INF; break; }
			if (arr[i][cur.y] == 'x') { dist = i - cur.x - 1; break; }
		}
		ret = min(ret, dist);
	} return ret;
}
void moveCluster(const vector<node>& cluster, int dist) {
	for (auto& cur : cluster) arr[cur.x + dist][cur.y] = 'x', arr[cur.x][cur.y] = '.';
}

void solve(int i, int round) {
	int j = cutBlock(i, round % 2);
	if (j == -1) return;

	FOR(dir, 4) {
		int ni = i + di[dir], nj = j + dj[dir];
		if (oob(ni, nj)) continue;
		if (arr[ni][nj] == '.') continue;
		vector<node> cluster = getCluster(ni, nj);
		if (!isCluster(cluster)) continue;
		moveCluster(cluster, getMoveDist(cluster));
		return;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c;
	FOR(i, r) cin >> arr[i];
	cin >> n; FOR(x, n) cin >> h, solve(r - h, x);
	FOR(i, r) cout << arr[i] << '\n';
}