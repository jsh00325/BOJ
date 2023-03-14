#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second
#define MEM(x, y) memset((x), (y), sizeof(x))

const int MX = 40001;
int n, m, d[MX], p[MX], lv[MX];
vector<pii> edge[MX];

void bfs() {
	MEM(d, -1); d[1] = 0; p[1] = -1;
	queue<int> q; q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (pii nxt : edge[cur]) {
			if (d[nxt.X] != -1) continue;
			d[nxt.X] = d[cur] + nxt.Y; p[nxt.X] = cur; lv[nxt.X] = lv[cur] + 1;
			q.push(nxt.X);
		}
	}
}
int lca(int x, int y) {
	if (lv[x] > lv[y]) swap(x, y);
	while (lv[x] != lv[y]) y = p[y];
	while (x != y) {
		x = p[x];
		y = p[y];
	}
	return x;
}
inline int dist(int x, int y) { return d[x] - d[y]; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
	bfs();

    cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		int lc = lca(a, b);
		cout << dist(a, lc) + dist(b, lc) << '\n';
	}
}