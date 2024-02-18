#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node { ll t1, t2, s; };

ll minSeg[44444];

void update(int idx, int l, int r, int tar_idx, ll val) {
	if (tar_idx < l || r < tar_idx) return;
	if (l == r) { minSeg[idx] = val; return; }

	int mid = (l + r) >> 1;
	update(idx<<1, l, mid, tar_idx, val);
	update((idx<<1)+1, mid+1, r, tar_idx, val);
	minSeg[idx] = min(minSeg[idx<<1], minSeg[(idx<<1)+1]);
}

ll query(int idx, int l, int r, int st, int en) {
	if (en < l || r < st) return LLONG_MAX;
	if (st <= l && r <= en) return minSeg[idx];

	int mid = (l + r) >> 1;
	ll lquery = query(idx<<1, l, mid, st, en);
	ll rquery = query((idx<<1)+1, mid+1, r, st, en);
	return min(lquery, rquery);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, e; cin >> n >> m >> e;
	vector<node> v(n+1);
	v[0] = {m-1, m-1, 0};
	for (int i = 1; i <= n; ++i) cin >> v[i].t1 >> v[i].t2 >> v[i].s;
	sort(v.begin(), v.end(), [](node& a, node& b) {
		return (a.t2 == b.t2 ? a.t1 < b.t1 : a.t2 < b.t2);
	});

	vector<int> ed_tm(n+1); for (int i = 0; i <= n; ++i) ed_tm[i] = v[i].t2;
	if (ed_tm.end()[-1] < e) { cout << -1; return 0; }

	for (int i = 1; i <= n; ++i) {
		node& cur = v[i];
		int bs = lower_bound(ed_tm.begin(), ed_tm.begin() + i, cur.t1-1) - ed_tm.begin();
		if (bs == i) update(1, 0, n, i, LLONG_MAX);
		else {
			ll cur_min = query(1, 0, n, bs, i-1);
			update(1, 0, n, i, (cur_min == LLONG_MAX ? LLONG_MAX : cur_min + cur.s));
		}
	}
	ll ans = query(1, 0, n, n, n);
	cout << (ans == LLONG_MAX ? -1 : ans);
}