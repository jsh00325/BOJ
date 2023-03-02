#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node { int to, x, y; };
struct node2 { int sx, sy, nd; };
struct cmp {
	bool operator() (const node2& a, const node2& b) {
		return a.sx * a.sy > b.sx * b.sy;
	}
};
const int INF = 0x3fffffff;
int n, m, d[21];
vector<node> adj[21];
priority_queue<node2, vector<node2>, cmp> pq;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			int a, b, x, y; cin >> a >> b >> x >> y;
			adj[a].push_back({ b, x, y });
			adj[b].push_back({ a, x, y });
		}

		for (int i = 1; i <= n; i++) d[i] = INF;
		d[1] = 0; pq.push({ 0, 0, 1 });
		while (!pq.empty()) {
			node2 cur = pq.top(); pq.pop();

			if (cur.sx * cur.sy != d[cur.nd]) continue;
			for (node nxt : adj[cur.nd]) {
				if (d[nxt.to] > (cur.sx + nxt.x) * (cur.sy + nxt.y)) {
					d[nxt.to] = (cur.sx + nxt.x) * (cur.sy + nxt.y);
					pq.push({ cur.sx + nxt.x, cur.sy + nxt.y, nxt.to });
				}
			}
		}
		cout << '#' << i << ' ' << (d[2] == INF ? -1 : d[2]) << '\n';
		for (int j = 1; j <= n; j++) adj[j].clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}