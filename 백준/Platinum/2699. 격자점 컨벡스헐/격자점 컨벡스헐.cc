#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
	ll x, y, dx, dy;
};

ll ccw(const point& a, const point& b, const point& c) {
	ll v1x = b.x - a.x, v1y = b.y - a.y;
	ll v2x = c.x - a.x, v2y = c.y - a.y;

	return v1x * v2y - v2x * v1y;
}

void stack_print(vector<point>& v, stack<int>& s) {
	if (s.empty()) return;
	int cur = s.top(); s.pop();

	stack_print(v, s);
	cout << v[cur].x << ' ' << v[cur].y << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<point> v(n);
		for (auto& i : v) cin >> i.x >> i.y;
		sort(v.begin(), v.end(), [](const point& a, const point& b) {
			return (a.y == b.y ? a.x < b.x : a.y > b.y);
		});

		for (int i = 1; i < n; ++i) {
			v[i].dx = v[i].x - v[0].x;
			v[i].dy = v[i].y - v[0].y;
		}
		sort(v.begin()+1, v.end(), [](const point& a, const point& b) {
			ll outer = a.dx * b.dy - b.dx * a.dy;
			if (outer) return outer < 0;
			else return (a.dx*a.dx + a.dy*a.dy) < (b.dx*b.dx + b.dy*b.dy);
		});

		stack<int> st;
		st.push(0), st.push(1);
		for (int cur = 2; cur < n; ++cur) {
			while (st.size() >= 2) {
				int prev = st.top(); st.pop();
				int pprev = st.top();

				if (ccw(v[pprev], v[prev], v[cur]) < 0) {
					st.push(prev);
					break;
				}
			}
			st.push(cur);
		}

		cout << st.size() << '\n';
		stack_print(v, st);
	}
}