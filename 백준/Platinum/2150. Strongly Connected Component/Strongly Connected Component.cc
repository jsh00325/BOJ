#include <bits/stdc++.h>
using namespace std;

const int MX = 1e4+1;
int v, e, cnt, dfsn[MX];
bool finished[MX];
vector<int> edge[MX];
vector<vector<int>> scc;
stack<int> st;

int dfs(int cur) {
	dfsn[cur] = ++cnt;
	st.push(cur);

	int ret = dfsn[cur];
	for (auto& nxt : edge[cur]) {
		// 해당 노드 방문 X
		if (!dfsn[nxt]) ret = min(ret, dfs(nxt));
		// 해당 노드를 방문은 했지만, 아직 SCC의 요소 X
		else if (!finished[nxt]) ret = min(ret, dfsn[nxt]);
	}

	if (ret == dfsn[cur]) {
		vector<int> curSCC;
		while (true) {
			int st_top = st.top(); st.pop();
			curSCC.push_back(st_top);
			finished[st_top] = true;
			if (st_top == cur) break;
		}
		sort(curSCC.begin(), curSCC.end());
		scc.push_back(curSCC);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
	}

	for (int i = 1; i <= v; ++i) if (!dfsn[i]) dfs(i);
	sort(scc.begin(), scc.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

	cout << scc.size() << '\n';
	for (auto& x : scc) {
		for (int vt : x) cout << vt << ' ';
		cout << "-1\n";
	}
}