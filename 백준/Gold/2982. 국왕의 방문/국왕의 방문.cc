#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)
typedef struct { int x, y; } Node;
struct cmp { bool operator() (const Node& a,const Node& b) { return a.x < b.x; } };

const int INF = 987654321;
int n, m, a, b, k, g, u, v, l, d[1001];
vector<int> gm;
vector<Node> edge[1001];
Node late_info[1001][1001];
priority_queue<Node, vector<Node>, cmp> pq;

int get_weight(int st, int en) {
	for (Node nxt : edge[st]) if (nxt.x == en) return nxt.y;
}
void dijk(int st, int t) {
	FOR1(i, n) d[i] = INF;
	d[st] = t; pq.push({ d[st], st });
	while (!pq.empty()) {
		Node cur = pq.top(); pq.pop();
		if (cur.x != d[cur.y]) continue;
		for (Node nxt : edge[cur.y]) {
			int w = nxt.y;

			Node& cur_late = late_info[cur.y][nxt.x];
			if (cur_late.x <= cur.x && cur.x < cur_late.y)
				w += cur_late.y - cur.x;

			if (d[nxt.x] > cur.x + w) {
				d[nxt.x] = cur.x + w;
				pq.push({ d[nxt.x], nxt.x });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	cin >> a >> b >> k >> g;
	gm.resize(g); FOR(i, g) cin >> gm[i];
	FOR(i, m) {
		cin >> u >> v >> l;
		edge[u].push_back({ v,l });
		edge[v].push_back({ u,l });
	}
	int cur = 0;
	for (int i = 0; i < g - 1; i++) {
		int w = get_weight(gm[i], gm[i + 1]);
		late_info[gm[i]][gm[i + 1]] = { cur, cur + w };
		late_info[gm[i + 1]][gm[i]] = { cur, cur + w };
		cur += w;
	}
	dijk(a, k); cout << d[b] - k;
}