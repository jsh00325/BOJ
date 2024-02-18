#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct point { ll idx, x, y, nx, ny; };

ll ccw(const point& a, const point& b, const point& c) {
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<point> v(n);
		for (int i = 0; i < n; ++i) {
			v[i].idx = i;
			cin >> v[i].x >> v[i].y;
		}
		sort(v.begin(), v.end(), [](const point& a, const point& b) {
			return (a.y == b.y ? a.x < b.x : a.y < b.y);
		});

		for (int i = 1; i < n; ++i) {
			v[i].nx = v[i].x - v[0].x;
			v[i].ny = v[i].y - v[0].y;
		}
		sort(v.begin()+1, v.end(), [](const point& a, const point& b) {
			ll outer = a.nx*b.ny - a.ny*b.nx;
			return (outer == 0 ? ((a.nx*a.nx + a.ny*a.ny) < (b.nx*b.nx + b.ny*b.ny)) : outer > 0);
		});

		int same_degree = n - 1;
		while (ccw(v[0], v[n-1], v[same_degree-1]) == 0) --same_degree;
		reverse(v.begin()+same_degree, v.end());

		for (auto& p : v) cout << p.idx << ' '; cout << '\n';
	}
}