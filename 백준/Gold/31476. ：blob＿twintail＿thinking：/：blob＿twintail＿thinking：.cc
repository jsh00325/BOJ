#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define X first
#define Y second

int d, n, u, t, a[1<<12];
bool cut[1<<12][2];

int nor_cnt = 0;
int bfs() {
	int ans = 0;
	a[1] = 0;
	queue<pii> q; q.push({1, u});
	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		ans = max(ans, a[cur.X]); ++nor_cnt;

		if (cut[cur.X][0] && cut[cur.X][1]) continue;
		if (!cut[cur.X][0] && !cut[cur.X][1]) {
			a[cur.X<<1] = a[cur.X] + cur.Y + t; q.push({cur.X<<1, cur.Y+t});
			a[(cur.X<<1)+1] = a[cur.X] + cur.Y + t; q.push({(cur.X<<1)+1, cur.Y+t});
		}
		else if (!cut[cur.X][0]){
			a[cur.X<<1] = a[cur.X] + cur.Y; q.push({cur.X<<1, cur.Y});
		}
		else {
			a[(cur.X<<1)+1] = a[cur.X] + cur.Y; q.push({(cur.X<<1)+1, cur.Y});
		}
	}
	return ans;
}

int vst_cnt = 0;
int dfs(int cur) {
	++vst_cnt;

	int ret = (cur != 1);
	if (!cut[cur][0]) {
		ret += dfs(cur<<1);
		if (vst_cnt != nor_cnt) ++ret;
	}
	if (!cut[cur][1]) {
		ret += dfs((cur<<1)+1);
		if (vst_cnt != nor_cnt) ++ret;
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> d >> n >> u >> t;
	for (int i = 0; i < n; ++i) {
		int s, e; cin >> s >> e;
		cut[s][e-(s<<1)] = 1;
	}
	for (int i = (1<<(d-1)); i < (1<<d); ++i) cut[i][0] = cut[i][1] = 1;

	int twin = bfs(), poni = dfs(1) * u;

	if (twin == poni) cout << ":blob_twintail_thinking:";
	else if (twin < poni) cout << ":blob_twintail_aww:";
	else cout << ":blob_twintail_sad:";
}