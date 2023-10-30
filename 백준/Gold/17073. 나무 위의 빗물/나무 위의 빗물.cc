#include <bits/stdc++.h>
using namespace std;

vector<int> edge[500001];

int countLeaf(int cur, int from) {
	if (edge[cur].size() == 1 && edge[cur][0] == from) return 1;
	int ret = 0;
	for (int nxt : edge[cur]) if (nxt != from) ret += countLeaf(nxt, cur);
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i < n; ++i ) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v), edge[v].push_back(u);
	} cout << fixed << setprecision(6) << (double)m / countLeaf(1, 0);	
}