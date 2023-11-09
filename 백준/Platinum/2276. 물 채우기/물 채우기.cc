#include <bits/stdc++.h>
using namespace std;
struct node { int x, y; };

const int di[4] = {0,1,0,-1}, dj[4] = {1,0,-1,0};
int n, m, arr[300][300], ans;
bool vst[300][300];
struct cmp { bool operator() (node& a, node& b) { return arr[a.x][a.y] > arr[b.x][b.y]; } };
priority_queue<node, vector<node>, cmp> pq;

void dfs(int x, int y, int curH) {
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + di[dir], ny = y + dj[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || vst[nx][ny]) continue;
		vst[nx][ny] = true;

		if (arr[nx][ny] > curH) pq.push({nx, ny});
		else { ans += curH - arr[nx][ny]; dfs(nx, ny, curH); }
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> arr[i][j]; 
		if (i == 0 || i == n-1 || j == 0 || j == m-1)
			pq.push({i, j}), vst[i][j] = true;
	}

	while (!pq.empty()) {
		node cur = pq.top(); pq.pop();
		dfs(cur.x, cur.y, arr[cur.x][cur.y]);
	} cout << ans;
}