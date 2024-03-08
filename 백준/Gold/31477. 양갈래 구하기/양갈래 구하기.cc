#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

const int MX = 1e5;
vector<pii> edge[MX+1], child[MX+1];

bool vst[MX+1];
void get_child(int cur) {
	vst[cur] = 1;

	for (auto nxt : edge[cur]) if (!vst[nxt.X]) {
		child[cur].push_back(nxt);
		get_child(nxt.X);
	}
}

int solve(int cur) {
	if (child[cur].empty()) return 0x7fffffff;

	int ret = 0;
	for (auto nxt : child[cur])
		ret += min(nxt.Y, solve(nxt.X));
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
	}

	get_child(1);
	cout << solve(1);
}