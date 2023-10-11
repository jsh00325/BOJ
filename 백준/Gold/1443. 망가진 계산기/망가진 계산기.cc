#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
struct node { int x, y; };

int d, p, MX = 1, ans = -1;
unordered_set<int> vst[31];

inline void update_max(int& orig, int nxt) { if (orig < nxt) orig = nxt; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> d >> p; FOR(i, d) MX *= 10;

	queue<node> q;
	q.push({0, 1}); vst[0].insert(1);
	while (!q.empty()) {
		node cur = q.front(); q.pop();
		if (cur.x == p) { update_max(ans, cur.y); continue; }

		for (int mul = 2; mul <= 9; ++mul) {
			int nxt = cur.y * mul; if (nxt >= MX) continue;
			if (vst[cur.x + 1].find(nxt) != vst[cur.x + 1].end()) continue;
			q.push({cur.x + 1, nxt}); vst[cur.x + 1].insert(nxt);
		}
	} cout << ans;
}