#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
struct node { int x, y; };

const int MX = 75000;
int n, tree[MX+7], tree_size;

void update(int x) {
	while (x <= tree_size) ++tree[x], x += (x & -x);
}
int query(int x) {
	int ans = 0;
	while (x > 0) ans += tree[x], x -= (x & -x);
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> n; MEM(tree, 0);
		vector<node> v(n);
		map<int, int> m;

		for (int i = 0; i < n; ++i) {
			cin >> v[i].x >> v[i].y;
			m.insert({v[i].y, 0});
		} tree_size = m.size();

		int idx = 0;
		for (auto& cur : m) cur.second = ++idx;

		sort(v.begin(), v.end(), [](const node& a, const node& b) { return (a.x == b.x ? a.y > b.y : a.x < b.x); });

		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += (i - query(m[v[i].y] - 1));
			update(m[v[i].y]);
		} cout << ans << '\n';	
	}	
}