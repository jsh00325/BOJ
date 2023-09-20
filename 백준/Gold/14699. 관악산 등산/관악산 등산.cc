#include <bits/stdc++.h>
using namespace std;
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

int hei[5001], dp[5001], ind[5001];
vector<int> edge[5001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	FOR1(i, n) cin >> hei[i];
	FOR1(x, m) {
		int a, b; cin >> a >> b;
		if (hei[a] > hei[b]) edge[a].push_back(b), ind[b]++;
		else edge[b].push_back(a), ind[a]++;
	}

	queue<int> q;
	FOR1(i, n) if (!ind[i]) q.push(i), dp[i] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int& nxt : edge[cur]) {
			dp[nxt] = max(dp[nxt], dp[cur] + 1);
			if (--ind[nxt] == 0) q.push(nxt);
		}
	}
	FOR1(i, n) cout << dp[i] << '\n';
}