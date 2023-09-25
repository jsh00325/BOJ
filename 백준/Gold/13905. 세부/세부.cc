#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

struct EDGE { int from, to, wei; };
int n, m, s, e, p[100001];
EDGE edges[300000];

int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	p[y] = x; return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> s >> e;
	FOR(i, m) cin >> edges[i].from >> edges[i].to >> edges[i].wei;
	sort(edges, edges+m, []	(const EDGE& a, const EDGE& b) { return a.wei > b.wei; });

	FOR1(i, n) p[i] = i;
	FOR(x, m) {
		merge(edges[x].from, edges[x].to);
		if (find(s) == find(e)) {
			cout << edges[x].wei; return 0;
		}
	} cout << 0;
}