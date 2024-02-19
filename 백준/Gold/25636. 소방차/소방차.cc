#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node { int v, w; };
struct pq_node { ll dist; int idx; };
struct cmp { bool operator() (const pq_node& a, const pq_node& b) { return a.dist > b.dist; } };

const int MX = 100003;
int n, m, s, t;
const ll INF = LLONG_MAX >> 1;
ll d[MX], wt[MX];
vector<node> edge[MX];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edge[u].push_back({v, w}), edge[v].push_back({u, w});
	} cin >> s >> t;

	for (int i = 1; i <= n; ++i) d[i] = INF;
	priority_queue<pq_node, vector<pq_node>, cmp> pq;
	d[s] = 0; wt[s] = a[s]; pq.push({d[s], s});
	while (!pq.empty()) {
		pq_node cur = pq.top(); pq.pop();
		if (d[cur.idx] != cur.dist) continue;

		for (auto& nxt : edge[cur.idx]) {
			if (d[nxt.v] > cur.dist + nxt.w) {
				d[nxt.v] = cur.dist + nxt.w;
				wt[nxt.v] = wt[cur.idx] + a[nxt.v];
				pq.push({d[nxt.v], nxt.v});
			}
			else if (d[nxt.v] == cur.dist + nxt.w && wt[nxt.v] < wt[cur.idx] + a[nxt.v]) {
				wt[nxt.v] = wt[cur.idx] + a[nxt.v];
			}
		}
	}
	
	if (d[t] == INF) cout << -1;
	else cout << d[t] << ' ' << wt[t];	
}