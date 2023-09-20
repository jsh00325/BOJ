#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

struct node {
	int x, y, stat;
	bool operator==(const node& other) {
		return x==other.x && y==other.y && stat==other.stat;
	}
} target;
typedef struct { node info; int dist; } qNode;
// (x, y) -> center point
// stat -> direction of log (0: -, 1: |)

int n, di[4] = {-1,1,0,0}, dj[4] = {0,0,-1,1};
string mp[50];
bool visit[50][50][2];
queue<qNode> q;

inline bool checkLog(int i, int j, int stat, char c) {
	if (stat == 0) return (mp[i][j]==c && mp[i][j+1]==c && mp[i][j+2]==c);
	else return (mp[i][j]==c && mp[i+1][j]==c && mp[i+2][j]==c);
}

// dir : (0-상(U) / 1-하(D) / 2-좌(L) / 3-우(R) / 4-회전(T))
bool movable(int i, int j, int stat, int dir) {
	if (dir == 4) {
		if (i==0 || i==n-1 || j==0 || j==n-1) return false;
		for (int di = -1; di <= 1; ++di)
			for (int dj = -1; dj <= 1; ++dj)
				if (mp[i+di][j+dj]=='1') return false;
		return true;
	}

	if (stat) { // |
		if (dir == 0) return i-2>=0 && mp[i-2][j] != '1';
		else if (dir == 1) return i+2<n && mp[i+2][j] != '1';
		else if (dir == 2) return j-1>=0 && mp[i-1][j-1] != '1' && mp[i][j-1] != '1' && mp[i+1][j-1] != '1';
		else if (dir == 3) return j+1<n && mp[i-1][j+1] != '1' && mp[i][j+1] != '1' && mp[i+1][j+1] != '1';
	}	
	else {		// ---
		if (dir == 0) return i-1>=0 && mp[i-1][j-1] != '1' && mp[i-1][j] != '1' && mp[i-1][j+1] != '1';
		else if (dir == 1) return i+1<n && mp[i+1][j-1] != '1' && mp[i+1][j] != '1' && mp[i+1][j+1] != '1';
		else if (dir == 2) return j-2>=0 && mp[i][j-2] != '1';
		else if (dir == 3) return j+2<n && mp[i][j+2] != '1';
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR(i, n) cin >> mp[i];

	// dir0 check
	FOR(i, n) FOR(j, n - 2) {
		if (checkLog(i, j, 0, 'B')) visit[i][j+1][0] = true, q.push({{i, j+1, 0}, 0});
		if (checkLog(i, j, 0, 'E')) target = {i, j+1, 0};
	}
	// dir1 check
	FOR(j, n) FOR(i, n - 2) {
		if (checkLog(i, j, 1, 'B')) visit[i+1][j][1] = true, q.push({{i+1, j, 1}, 0});
		if (checkLog(i, j, 1, 'E')) target = {i+1, j, 1};
	}

	while (!q.empty()) {
		node cur = q.front().info;
		int curDist = q.front().dist;
		q.pop();

		if (cur == target) {
			cout << curDist;
			return 0;
		}

		FOR(dir, 5) if (movable(cur.x, cur.y, cur.stat, dir)) {
			int ni, nj, nstat;
			if (dir == 4) ni = cur.x, nj = cur.y, nstat = !cur.stat;
			else ni = cur.x + di[dir], nj = cur.y + dj[dir], nstat = cur.stat;

			if (visit[ni][nj][nstat]) continue;
			q.push({{ni, nj, nstat}, curDist+1});
			visit[ni][nj][nstat] = true;
		}
	}
	cout << 0;	
}