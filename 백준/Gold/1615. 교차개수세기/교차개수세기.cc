#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
struct node { int x, y; };

int n, m, fw[2001];

void update(int x) {
	while (x <= n) {
		fw[x]++;
		x += x & (-x);
	}
}
ll query(int x) {
	ll rslt = 0;
	while (x > 0) {
		rslt += fw[x];
		x -= x & (-x);
	} return rslt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	vector<node> v(m);
	FOR(i, m) cin >> v[i].x >> v[i].y;
	sort(v.begin(), v.end(), [](const node& a, const node& b) {
		if (a.x == b.x) return a.y > b.y;
		else return a.x > b.x;
	});

	ll ans = 0;
	for (auto &nd : v) {
		ans += query(nd.y - 1);
		update(nd.y);
	} cout << ans;
}