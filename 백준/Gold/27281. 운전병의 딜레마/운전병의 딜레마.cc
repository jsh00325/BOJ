#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct road { ll v, t, s; };
struct node { ll dst, u; };
struct cmp {
	bool operator() (const node& a, const node& b) {
		return a.dst > b.dst;
	}
};

const ll MX = 50001, INF = 9876543210;
ll n, m, T, d[MX];
vector<road> edge[MX];

bool solve(ll x) {
	priority_queue<node, vector<node>, cmp> pq;
	for (int i = 1; i <= n; ++i) d[i] = INF;
	
	d[1] = 0; pq.push({d[1], 1});
	while (!pq.empty()) {
		node cur = pq.top(); pq.pop();
		if (d[cur.u] != cur.dst) continue;

		for (auto& nxt : edge[cur.u]) {
			ll w = (nxt.s <= x ? 0 : nxt.s - x);
			if (d[nxt.v] > cur.dst + nxt.t + w) {
				d[nxt.v] = cur.dst + nxt.t + w;
				pq.push({d[nxt.v], nxt.v});
			}
		}
	}
	return d[n] <= T;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> T;
	ll mn_s = 0x7fffffff, mx_s = -1;
	for (int i = 0; i < m; ++i) {
		ll u, v, t, s;
		cin >> u >> v >> t >> s;

		edge[u].push_back({v, t, s});
		edge[v].push_back({u, t, s});

		mn_s = min(mn_s, s);
		mx_s = max(mx_s, s);
	}

	ll st = 0, en = mx_s;
	while (st < en) {
		ll mid = (st + en) / 2;

		if (solve(mid)) en = mid;
		else st = mid + 1;
	}
	cout << (solve(en) ? en : -1);
}