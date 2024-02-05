#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node { ll x, y; };
const int NEG_INF = -0x7ffffff7;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<node> v(2*n+1);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y;
		v[i+n].x = v[i].x, v[i+n].y = v[i].y;
	} v[2*n].x = v[0].x, v[2*n].y = v[0].y;

	int st_idx = 0, mn_x = v[0].x, mn_y = v[0].y;
	for (int i = 1; i < n; ++i) if ((v[i].x < mn_x) || (v[i].x == mn_x && v[i].y < mn_y))
		st_idx = i, mn_x = v[i].x, mn_y = v[i].y;
	
	vector<node> pnt; int idx = NEG_INF, cnt = 0;
	for (int i = st_idx + 1; i <= st_idx + n; ++i) if (v[i-1].x == v[i].x && v[i-1].y * v[i].y < 0) {
		if (idx == NEG_INF) idx = v[i].x;
		else pnt.push_back({idx, cnt}), pnt.push_back({v[i].x, cnt++}), idx = NEG_INF;
	}
	sort(pnt.begin(), pnt.end(), [](const node& a, const node& b) { return a.x < b.x; });

	vector<int> vst(cnt, -1);
	stack<int> st;

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < pnt.size(); ++i) {
		if (vst[pnt[i].y] != -1) {
			st.pop();
			ans1 += (st.empty());
			ans2 += (vst[pnt[i].y] + 1 == i);
		}
		else st.push(pnt[i].y), vst[pnt[i].y] = i;
	} cout << ans1 << ' ' << ans2;
}