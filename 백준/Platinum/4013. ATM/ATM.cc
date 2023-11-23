#include <bits/stdc++.h>
using namespace std;

const int MX = 500001;
int n, m, cash[MX], s, p, cnt, dfsn[MX], scc_cnt, scc_tp[MX], scc_cash[MX], scc_ind[MX], scc_rslt[MX];
bool finished[MX], isRes[MX], scc_res[MX], scc_pos[MX];
vector<int> edge[MX], scc_edge[MX];
stack<int> st;

int tarjan_scc(int cur) {
	dfsn[cur] = ++cnt;
	st.push(cur);

	int ret = dfsn[cur];
	for (auto& nxt : edge[cur]) {
		if (!dfsn[nxt]) ret = min(ret, tarjan_scc(nxt));
		else if (!finished[nxt]) ret = min(ret, dfsn[nxt]); 
	}

	if (ret == dfsn[cur]) {
		while (true) {
			int st_top = st.top(); st.pop();
			scc_tp[st_top] = scc_cnt;
			finished[st_top] = true;
			scc_cash[scc_cnt] += cash[st_top];
			if (isRes[st_top]) scc_res[scc_cnt] = true;
			if (st_top == cur) break;
		} ++scc_cnt;
	}
	return ret;
}

void scc_dfs(int cur) {
	scc_pos[cur] = true;
	for (int& nxt : scc_edge[cur]) if (!scc_pos[nxt]) scc_dfs(nxt);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i) cin >> cash[i];

	cin >> s >> p;
	for (int i = 0; i < p; ++i) {
		int x; cin >> x;
		isRes[x] = true;
	}

	for (int i = 1; i <= n; ++i) if (!dfsn[i]) tarjan_scc(i);

	for (int cur = 1; cur <= n; ++cur) {
		for (int& nxt : edge[cur]) if (scc_tp[cur] != scc_tp[nxt])
			scc_edge[scc_tp[cur]].push_back(scc_tp[nxt]);
	}

	int stSCC = scc_tp[s]; scc_dfs(stSCC);

	for (int cur = 0; cur < scc_cnt; ++cur) if (scc_pos[cur])
		for (int& nxt : scc_edge[cur]) if (scc_pos[nxt]) ++scc_ind[nxt];

	queue<int> q;
	for (int cur = 0; cur < scc_cnt; ++cur) if (scc_pos[cur]) {
		scc_rslt[cur] = scc_cash[cur];
		if (scc_ind[cur] == 0) q.push(cur);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int& nxt : scc_edge[cur]) if (scc_pos[nxt]) {
			scc_rslt[nxt] = max(scc_rslt[nxt], scc_rslt[cur] + scc_cash[nxt]);
			if (--scc_ind[nxt] == 0) q.push(nxt);
		}
	}

	int ans = 0;
	for (int i = 0; i < scc_cnt; ++i) if (scc_pos[i] && scc_res[i]) ans = max(ans, scc_rslt[i]);
	cout << ans;
}