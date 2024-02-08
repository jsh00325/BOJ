#include <bits/stdc++.h>
using namespace std;

const int MX = 200001;
vector<int> edge[MX];
int p[MX]; bool vst[MX];

int find(int x) {
	if (p[x] < 0) return x;
	else return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (p[x] < p[y]) { p[x] += p[y]; p[y] = x; }
	else { p[y] += p[x]; p[x] = y; }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	vector<int> cut(n), ans(n);
	for (int i = 0; i < n; ++i) cin >> cut[i];

	memset(p, -1, sizeof(p));
	for (int i = n-1; i >= 0; --i) {
		int &cur = cut[i];
		vst[cur] = 1;
		for (auto& nxt : edge[cur]) if (vst[nxt]) merge(cur, nxt);
		ans[i] = (p[find(cur)] + n-i == 0);
	}
	for (int i = 0; i < n; ++i) cout << (ans[i] ? "CONNECT" : "DISCONNECT") << '\n';
	cout << "DISCONNECT";	
}