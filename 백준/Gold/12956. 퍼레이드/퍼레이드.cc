#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
struct node { int x, y; };

const int INF = 0x3f3f3f3f;
int n, m, adj[100][100];
inline int getArr(int arr[100][100], int x, int y) {
	return (x == y ? 0 : (x > y ? arr[y][x] : arr[x][y]));
}
void copyAdj(int copied[100][100]) {
	for (int i = 0; i < n-1; ++i) for (int j = i+1; j < n; ++j)
		copied[i][j] = adj[i][j];
}
void fw(int arr[100][100]) {
	for (int k = 0; k < n; k++)	for (int i = 0; i < n-1; ++i) for (int j = i+1; j < n; ++j)
		if (arr[i][j] > getArr(arr, i, k) + getArr(arr, k, j))
			arr[i][j] = getArr(arr, i, k) + getArr(arr, k, j);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR(i, n) FOR(j, n) adj[i][j] = INF;
	vector<node> edges(m);
	FOR(i, m) {
		int s, e, w; cin >> s >> e >> w;
		if (s > e) swap(s, e);
		adj[s][e] = w, edges[i] = {s, e};
	}

	int orig[100][100], temp[100][100];
	copyAdj(orig), fw(orig);

	for (int i = 0; i < m; i++) {
		copyAdj(temp); temp[edges[i].x][edges[i].y] = INF; fw(temp);
		int ans = 0;
		for (int i = 0; i < n-1; ++i) for (int j = i+1; j < n; ++j)
			if (orig[i][j] < temp[i][j]) ++ans;
		cout << ans << ' ';
	}
}