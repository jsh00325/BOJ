#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

struct node { int x, y, w; };
struct cmd { bool operator() (const node& a, const node& b) { return a.w > b.w; } };

const int INF = 0x3f3f3f3f, di[4]={0,1,0,-1}, dj[4]={1,0,-1,0};
int n, m, t, d, goDist[30][30], backDist[30][30];
string mp[30];
priority_queue<node, vector<node>, cmd> pq;

inline bool oob(int i, int j) { return i < 0 || j < 0 || i >= n || j >= m; }
inline int getHeight(char c) { return c - (c >= 'a' ? 'a'-26 : 'A'); }
inline void maxUpdate(int& orig, int nxt) { if (orig < nxt) orig = nxt; }
inline int goWeightFunction(int curH, int nxtH) {
	return (curH < nxtH ? (nxtH - curH) * (nxtH - curH) : 1);
}
inline int backWeightFunction(int curH, int nxtH) {
	return (curH > nxtH ? (nxtH - curH) * (nxtH - curH) : 1);
}

void dijkstra(int dist[30][30], int (*weightFunction)(int, int)) {
	FOR(i, n) FOR(j, m) dist[i][j] = INF;
	dist[0][0] = 0; pq.push({0,0,0});

	while (!pq.empty()) {
		node cur = pq.top(); pq.pop();
		if (dist[cur.x][cur.y] != cur.w) continue;

		FOR(dir, 4) {
			int ni = cur.x + di[dir], nj = cur.y + dj[dir];
			if (oob(ni, nj)) continue;
			int curH = getHeight(mp[cur.x][cur.y]), nxtH = getHeight(mp[ni][nj]);
			if (abs(curH - nxtH) > t) continue;
			int weight = weightFunction(curH, nxtH);

			int& nxtDist = dist[ni][nj];
			if (nxtDist > cur.w + weight) {
				nxtDist = cur.w + weight;
				if (nxtDist <= d) pq.push({ni, nj, nxtDist});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> t >> d;
	FOR(i, n) cin >> mp[i];

	dijkstra(goDist, goWeightFunction);
	dijkstra(backDist, backWeightFunction);

	int ans = -1;
	FOR(i, n) FOR(j, m) if (goDist[i][j] + backDist[i][j] <= d)
		maxUpdate(ans, getHeight(mp[i][j]));
	cout << ans;
}