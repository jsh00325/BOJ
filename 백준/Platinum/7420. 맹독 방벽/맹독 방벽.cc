#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double PI = acos(-1);

struct point {
	ll x, y, dx, dy;
};

ll ccw(const point& a, const point& b, const point& c) {
	ll v1x = b.x - a.x, v1y = b.y - a.y;
	ll v2x = c.x - a.x, v2y = c.y - a.y;
	return v1x * v2y - v1y * v2x;
}

double get_dist(const point& a, const point& b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, l; cin >> n >> l;
	vector<point> v(n);
	for (auto& i : v) cin >> i.x >> i.y;

	sort(v.begin(), v.end(), [](const point& a, const point& b) {
		return (a.y == b.y ? a.x < b.x : a.y < b.y);
	});

	for (int i = 1; i < n; ++i) v[i].dx = v[i].x - v[0].x, v[i].dy = v[i].y - v[0].y;
	sort(v.begin()+1, v.end(), [](const point& a, const point& b) {
		ll outer = a.dx * b.dy - a.dy * b.dx;
		if (outer) return outer > 0;
		else return (a.dx*a.dx + a.dy*a.dy) < (b.dx*b.dx + b.dy*b.dy);
	});

	stack<int> st;
	st.push(0), st.push(1);
	for (int cur = 2; cur < n; ++cur) {
		while (st.size() >= 2) {
			int prev = st.top(); st.pop();
			int pprev = st.top();

			if (ccw(v[pprev], v[prev], v[cur]) > 0) {
				st.push(prev);
				break;
			}
		}	
		st.push(cur);
	}

	int convex_cnt = st.size();
	
	vector<int> convex(convex_cnt + 2);
	for (int i = convex_cnt; i >= 1; --i) {
		convex[i] = st.top(); st.pop();
	}
	convex[0] = convex.end()[-2], convex.end()[-1] = convex[1];

	double ans = 0;
	for (int i = 1; i <= convex_cnt; ++i) {
		point &prv = v[convex[i-1]], &cur = v[convex[i]], &nxt = v[convex[i+1]];
		double ad = get_dist(prv, cur), bd = get_dist(cur, nxt);
		ll ax = prv.x - cur.x, ay = prv.y - cur.y;
		ll bx = nxt.x - cur.x, by = nxt.y - cur.y;
		double theta = acos((double)(ax*bx + ay*by) / (ad * bd));

		ans += (double)l * (PI - theta) + bd;
	}
	
	cout << fixed; cout.precision(0);
	cout << ans;
}