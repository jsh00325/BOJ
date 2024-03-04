#include <bits/stdc++.h>
using namespace std;

struct node { 
	string stat;
	int bi, bj, ri, rj;
	bool bc, rc;
};

int n, m;
string orig[10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	node init;
	init.stat = "";
	for (int i = 0; i < n; ++i) cin >> orig[i];
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (orig[i][j] == 'R') init.ri = i, init.rj = j, orig[i][j] = '.';
		else if (orig[i][j] == 'B') init.bi = i, init.bj = j, orig[i][j] = '.';
	}
	init.bc = init.rc = true;

	queue<node> q;
	q.push(init);

	while (!q.empty()) {
		node cur = q.front(); q.pop();

		if (!cur.rc && cur.bc) {
			cout << cur.stat.size() << '\n' << cur.stat;
			return 0;
		}
		if (cur.stat.size() == 10) continue;

		for (int dir = 0; dir < 4; ++dir) {
			int di = ("0211"[dir]-'1'), dj = ("1102"[dir]-'1');

			node nxt;
			nxt.stat = cur.stat + ("UDLR"[dir]);
			nxt.ri = cur.ri, nxt.rj = cur.rj;
			nxt.bi = cur.bi, nxt.bj = cur.bj;
			nxt.rc = true, nxt.bc = true;	

			bool rm = (orig[nxt.ri + di][nxt.rj + dj] != '#');
			bool bm = (orig[nxt.bi + di][nxt.bj + dj] != '#');
			bool red_pri = false;

			if (dir == 0) red_pri = (nxt.ri < nxt.bi);
			else if (dir == 1) red_pri = (nxt.ri > nxt.bi);
			else if (dir == 2) red_pri = (nxt.rj < nxt.bj);
			else red_pri = (nxt.rj > nxt.bj);

			while (rm || bm) {
				if (red_pri) {
					if (rm) {
						nxt.ri += di, nxt.rj += dj;
						if (orig[nxt.ri][nxt.rj] == 'O') nxt.rc = false, rm = false;
						else rm = (orig[nxt.ri + di][nxt.rj + dj] != '#');
					}
					if (bm) {
						if (nxt.rc && (nxt.bi + di == nxt.ri) && (nxt.bj + dj == nxt.rj)) bm = false;
						else {
							nxt.bi += di, nxt.bj += dj;
							if (orig[nxt.bi][nxt.bj] == 'O') nxt.bc = false, bm = false;
							else bm = (orig[nxt.bi + di][nxt.bj + dj] != '#');
						}
					}
				}
				else {
					if (bm) {
						nxt.bi += di, nxt.bj += dj;
						if (orig[nxt.bi][nxt.bj] == 'O') nxt.bc = false, bm = false;
						else bm = (orig[nxt.bi + di][nxt.bj + dj] != '#');
					}
					if (rm) {
						if (nxt.bc && (nxt.ri + di == nxt.bi) && (nxt.rj + dj == nxt.bj)) rm = false;
						else {
							nxt.ri += di, nxt.rj += dj;
							if (orig[nxt.ri][nxt.rj] == 'O') nxt.rc = false, rm = false;
							else rm = (orig[nxt.ri + di][nxt.rj + dj] != '#');
						}
					}
				}
			}
			if (nxt.bc) q.push(nxt);
		}
	}
	cout << -1;
}