#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)
typedef struct { int x, y, time; } node;

const int di[8] = {-1,-1,-1,0,0,1,1,1}, dj[8] = {-1,0,1,-1,1,-1,0,1};
int h, w, arr[1000][1000], chk[1000][1000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> h >> w;
	FOR(i, h) {
		string s; cin >> s;
		FOR(j, w) arr[i][j] = (s[j] == '.' ? 0 : s[j] - '0');
	}
	FOR1(i, h-2) FOR1(j, w-2) FOR(dir, 8)
		chk[i][j] += (arr[i + di[dir]][j + dj[dir]] == 0);

	queue<node> q;
	FOR(i, h) FOR(j, w) if (arr[i][j] && arr[i][j] <= chk[i][j]) q.push({i, j, 1}), arr[i][j] = 0;

	int ans = 0;
	while (!q.empty()) {
		node& cur = q.front(); ans = cur.time;

		FOR(dir, 8) {
			int ni = cur.x + di[dir], nj = cur.y + dj[dir];
			if (arr[ni][nj] == 0) continue;
			if (arr[ni][nj] > (++chk[ni][nj])) continue;
			q.push({ni, nj, cur.time + 1}); arr[ni][nj] = 0;
		}
		q.pop();
	}
	cout << ans;
}