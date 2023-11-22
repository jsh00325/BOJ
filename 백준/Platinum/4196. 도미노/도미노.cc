#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))

const int MX = 1e5+1;
int n, m, cnt, scc_cnt, dfsn[MX], scc_type[MX];
bool finished[MX];
vector<int> edge[MX];
stack<int> st;

int scc_tarjan(int cur) {
	dfsn[cur] = ++cnt;
	st.push(cur);

	int ret = dfsn[cur];
	for (auto& nxt : edge[cur]) {
		if (!dfsn[nxt]) ret = min(ret, scc_tarjan(nxt));
		else if (!finished[nxt]) ret = min(ret, dfsn[nxt]);
	}

	if (ret == dfsn[cur]) {
		while (true) {
			int st_top = st.top(); st.pop();
			scc_type[st_top] = scc_cnt;
			finished[st_top] = true;
			if (st_top == cur) break;
		} ++scc_cnt;
	}
	return ret;
}

void init() {
	for (int i = 1; i <= n; ++i) edge[i].clear();
	MEM(finished, 0), MEM(dfsn, 0);
	while (!st.empty()) st.pop();
	cnt = scc_cnt = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			int x, y; cin >> x >> y;
			edge[x].push_back(y);
		}

		for (int i = 1; i <= n; ++i) if (!dfsn[i]) scc_tarjan(i);
		
		vector<int> ind(scc_cnt);
		for (int cur = 1; cur <= n; cur++) for (auto& nxt : edge[cur])
			if (scc_type[cur] != scc_type[nxt]) ++ind[scc_type[nxt]];
		
		int ans = 0;
		for (auto& x : ind) ans += (x == 0);
		cout << ans << '\n';

		init();
	}
}