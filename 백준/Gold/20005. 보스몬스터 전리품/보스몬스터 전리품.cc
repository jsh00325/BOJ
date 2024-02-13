#include <bits/stdc++.h>
using namespace std;
struct node { int x, y; };

int r, c, p, hp, vst[1000][1000], dps[30];
string arr[1000];

inline bool oob(int i, int j) { return i < 0 || i >= r || j < 0 || j >= c; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c >> p;
	for (int i = 0; i < r; ++i) cin >> arr[i];
	for (int i = 0; i < p; ++i) {
		char a; int x; cin >> a >> x;
		dps[a-'a'] = x;
	} cin >> hp;
	
	vector<node> v;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) if (arr[i][j] == 'B') {
		memset(vst, -1, sizeof(vst));
		queue<node> q;
		q.push({i, j}); vst[i][j] = 0;
		while (!q.empty()) {
			node cur = q.front(); q.pop();
			int& cur_vst = vst[cur.x][cur.y];
			char& cur_arr = arr[cur.x][cur.y];

			if ('a' <= cur_arr && cur_arr <= 'z') v.push_back({cur_vst, dps[cur_arr-'a']});

			for (int dir = 0; dir < 4; ++dir) {
				int nx = cur.x + ("1012"[dir]-'1'), ny = cur.y + ("0121"[dir] - '1');
				if (oob(nx, ny) || arr[nx][ny] == 'X' || vst[nx][ny] != -1) continue;
				q.push({nx, ny}); vst[nx][ny] = cur_vst + 1;
			}
		}
	}

	int mx_peo = 0;
	for (int i = 1; i <= p; ++i) {
		int tme = v[i-1].x;

		int dmg = 0;
		for (auto& x : v) if (x.x < tme) dmg += (tme - x.x) * x.y;
		if (dmg < hp) mx_peo = i;
	}
    cout << mx_peo;
}