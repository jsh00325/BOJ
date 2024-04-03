#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node { ll x, y; };
const int di[5] = {0,  0, 1, 0, -1}, dj[5] = {0, 1, 0, -1, 0};
ll dp[100001][5];

inline ll get_dist(ll x1, ll y1, ll x2, ll y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void min_update(ll& orig, ll val) {
	if (orig > val) orig = val;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	vector<node> v(n+1);
	for (auto& i : v) cin >> i.x >> i.y;

	for (int dir = 0; dir < 5; ++dir) {
		dp[1][dir] = get_dist(v[1].x + di[dir], v[1].y + dj[dir], v[0].x, v[0].y);
	}

	for (int idx = 2; idx <= n; ++idx) for (int cur = 0; cur < 5; ++cur) {
		node &pn = v[idx-1], &cn = v[idx];
		dp[idx][cur] = LONG_LONG_MAX;
		for (int prv = 0; prv < 5; ++prv) {
			ll cur_dist = get_dist(pn.x + di[prv], pn.y + dj[prv], cn.x + di[cur], cn.y + dj[cur]);
			min_update(dp[idx][cur], dp[idx-1][prv] + cur_dist);
		}
	}

	ll ans = LONG_LONG_MAX;
	for (int dir = 0; dir < 5; ++dir) min_update(ans, dp[n][dir]);
	cout << ans;	
}