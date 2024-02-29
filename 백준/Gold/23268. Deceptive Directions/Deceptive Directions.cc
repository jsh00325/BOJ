#include <bits/stdc++.h>
using namespace std;
struct node { int x, y; };

int h, w, dist[1000][1000];
bool vst[1000][1000];
string arr[1000], inst;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> w >> h;
	for (int i = 0; i < h; ++i) cin >> arr[i];
	cin >> inst;

	int si, sj;
	for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j)
		if (arr[i][j] == 'S') si = i, sj = j;

	queue<node> q;
	memset(dist, -1, sizeof(dist));
	q.push({si, sj}); dist[si][sj] = 0;
	while (!q.empty()) {
		node cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int ni = cur.x + ("1102"[dir]-'1'), nj = cur.y + ("0211"[dir]-'1');
			if (arr[ni][nj] == '#' || dist[ni][nj] != -1) continue;
			q.push({ni, nj}); dist[ni][nj] = dist[cur.x][cur.y] + 1;
		}
	}

	memset(vst, 0, sizeof(vst));
	q.push({si, sj}); vst[si][sj] = 1;
	
	while (!q.empty()) {
		node cur = q.front(); q.pop();
		int curDist = dist[cur.x][cur.y];

		if (curDist == inst.size()) {
			arr[cur.x][cur.y] = '!'; continue;
		}

		// EWSN
		for (int dir = 0; dir < 4; ++dir) if (inst[curDist] != "EWSN"[dir]) {
			int ni = cur.x + ("1120"[dir]-'1'), nj = cur.y + ("2011"[dir]-'1');
			if (arr[ni][nj] == '#' || vst[ni][nj] || dist[ni][nj] != curDist + 1) continue;
			q.push({ni, nj}); vst[ni][nj] = 1;
		}
	}

	for (int i = 0; i < h; ++i) cout << arr[i] << '\n';
}