#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct point { ll x, y, nx, ny; };

// ab의 기준에서 c의 위치
ll ccw(const point& a, const point& b, const point& c) {
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<point> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y;

	sort(v.begin(), v.end(), [](const point& a, const point& b) {
		return (a.y == b.y ? a.x < b.x : a.y < b.y);
	});
	
	for (int i = 1; i < n; ++i) v[i].nx = v[i].x - v[0].x, v[i].ny = v[i].y - v[0].y;
	sort(v.begin()+1, v.end(), [](const point& a, const point& b) {
		ll outer = a.nx*b.ny - b.nx*a.ny;
		return (outer == 0 ? ((a.nx*a.nx + a.ny*a.ny) < (b.nx*b.nx + b.ny*b.ny)) : (outer > 0));
	});

	stack<int> st;
	st.push(0), st.push(1);
	int nxt = 2;

	while (nxt < n) {
		while (st.size() >= 2) {
			int t1 = st.top(); st.pop();
			int t2 = st.top();

			if (ccw(v[t2], v[t1], v[nxt]) > 0) {
				st.push(t1); break;
			}
		}
		st.push(nxt++);
	} cout << st.size();
}