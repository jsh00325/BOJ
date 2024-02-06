#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node { int x, y, w; };
struct sn { ll lmx, rmx, mx, sf; } seg[3000*4 + 1];

void update(int idx, int l, int r, int tar, int val) {
	if (tar < l || r < tar) return;
	if (l == r) {
		seg[idx].lmx += val, seg[idx].rmx += val, seg[idx].mx += val, seg[idx].sf += val;
		return;
	}

	int mid = (l + r) >> 1, lc_idx = idx << 1, rc_idx = (idx << 1) + 1;
	update(lc_idx, l, mid, tar, val), update(rc_idx, mid+1, r, tar, val);
	seg[idx].lmx = max(seg[lc_idx].lmx, seg[lc_idx].sf + seg[rc_idx].lmx);
	seg[idx].rmx = max(seg[lc_idx].rmx + seg[rc_idx].sf, seg[rc_idx].rmx);
	seg[idx].mx = max(max(seg[lc_idx].mx, seg[rc_idx].mx), seg[lc_idx].rmx + seg[rc_idx].lmx);
	seg[idx].sf = seg[lc_idx].sf + seg[rc_idx].sf;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<node> v(n);
	vector<int> xc(n), yc(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y >> v[i].w;
		xc[i] = v[i].x, yc[i] = v[i].y;
	}
	sort(xc.begin(), xc.end()), sort(yc.begin(), yc.end());
	xc.erase(unique(xc.begin(), xc.end()), xc.end());
	yc.erase(unique(yc.begin(), yc.end()), yc.end());

	vector<node> ycv[3000];
	for (int i = 0; i < n; ++i) {
		int r = lower_bound(xc.begin(), xc.end(), v[i].x) - xc.begin();
		int c = lower_bound(yc.begin(), yc.end(), v[i].y) - yc.begin();
		ycv[r].push_back({r, c, v[i].w});
	}

	ll ans = 0;
	for (int r1 = 0; r1 < xc.size(); ++r1) {
		memset(seg, 0, sizeof(seg));
		for (int r2 = r1; r2 < xc.size(); ++r2) {
			for (auto& c : ycv[r2]) update(1, 0, yc.size()-1, c.y, c.w);
			ans = max(ans, max(max(seg[1].lmx, seg[1].rmx), seg[1].mx));
		}
	} cout << ans;
}