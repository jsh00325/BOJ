#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second

const ll INF = 1e15;
ll n, m, arr[300][300], d[90002], st, en;
int di[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dj[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

inline int node(int i, int j) { return i * m + j + 1; }
inline bool oob(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }

ll dijkstra() {
	typedef pair<ll, pii> pllpii;
	priority_queue<pllpii, vector<pllpii>, greater<pllpii>> pq;
	for (int i = 0; i <= en; i++) d[i] = INF;

	// 처음 시작할 떄에 해당하는 다익
	for (int j = 1; j < m; j++) {
		if (arr[0][j] == -1) continue;
		d[node(0, j)] = (arr[0][j] == -2 ? 0 : arr[0][j]);
		pq.push({ d[node(0, j)], {0, j} });
	}
	for (int i = 1; i < n - 1; i++) {
		if (arr[i][m - 1] == -1) continue;
		d[node(i, m - 1)] = (arr[i][m - 1] == -2 ? 0 : arr[i][m - 1]);
		pq.push({ d[node(i, m - 1)], {i, m - 1} });
	}

	while (!pq.empty()) {
		ll w = pq.top().X; pii cur = pq.top().Y; pq.pop();
		if (w != d[node(cur.X, cur.Y)]) continue;

		for (int dir = 0; dir < 8; dir++) {
			int nxti = cur.X + di[dir], nxtj = cur.Y + dj[dir];
			if (oob(nxti, nxtj)) continue;
			if (arr[nxti][nxtj] == -1) continue;
			ll nxtw = (arr[nxti][nxtj] == -2 ? 0 : arr[nxti][nxtj]);
			if (d[node(nxti, nxtj)] > w + nxtw) {
				d[node(nxti, nxtj)] = w + nxtw;
				pq.push({ d[node(nxti, nxtj)] , {nxti, nxtj} });
			}
		}
	}

	ll ans = INF;
	for (int i = 1; i < n; i++) ans = min(ans, d[node(i, 0)]);
	for (int j = 1; j < m - 1; j++) ans = min(ans, d[node(n - 1, j)]);
	return ans == INF ? -1 : ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	en = n * m + 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	cout << dijkstra();
}