#include <bits/stdc++.h>
using namespace std;

struct point { double x, y; };
struct line { point a, b; };

inline void min_update(double& tar, double val) { if (tar > val) tar = val; }
double outer_product(point a, point b) { return a.x*b.y - b.x*a.y; }
double inner_product(point a, point b) { return a.x*b.x + a.y*b.y; }
double get_dist(const point& a, const point& b) { return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); }
point get_vector(const point& a, const point& b) { return {b.x-a.x, b.y-a.y}; }
double get_vertical_dist(const line& l, const point& p) {
	return abs(outer_product(get_vector(p, l.a), get_vector(p, l.b))) / get_dist(l.a, l.b);
}

double get_minimum_dist(const line& l1, const line& l2) {
	double ans = 99999999;

	// l1입장에서 봤을 때 l2.a와의 최솟값 계산
	double cos1 = inner_product(get_vector(l1.a, l1.b), get_vector(l1.a, l2.a));
	double cos2 = inner_product(get_vector(l1.b, l1.a), get_vector(l1.b, l2.a));
	if (cos1 < 0) min_update(ans, get_dist(l1.a, l2.a));
	else if (cos2 < 0) min_update(ans, get_dist(l1.b, l2.a));
	else min_update(ans, get_vertical_dist(l1, l2.a));

	// l1입장에서 봤을 때 l2.b와의 최솟값 계산
	cos1 = inner_product(get_vector(l1.a, l1.b), get_vector(l1.a, l2.b));
	cos2 = inner_product(get_vector(l1.b, l1.a), get_vector(l1.b, l2.b));
	if (cos1 < 0) min_update(ans, get_dist(l1.a, l2.b));
	else if (cos2 < 0) min_update(ans, get_dist(l1.b, l2.b));
	else min_update(ans, get_vertical_dist(l1, l2.b));
	
	// l2입장에서 봤을 때 l1.a와의 최솟값 계산
	cos1 = inner_product(get_vector(l2.a, l2.b), get_vector(l2.a, l1.a));
	cos2 = inner_product(get_vector(l2.b, l2.a), get_vector(l2.b, l1.a));
	if (cos1 < 0) min_update(ans, get_dist(l2.a, l1.a));
	else if (cos2 < 0) min_update(ans, get_dist(l2.b, l1.a));
	else min_update(ans, get_vertical_dist(l2, l1.a));

	// l2입장에서 봤을 때 l1.b와의 최솟값 계산
	cos1 = inner_product(get_vector(l2.a, l2.b), get_vector(l2.a, l1.b));
	cos2 = inner_product(get_vector(l2.b, l2.a), get_vector(l2.b, l1.b));
	if (cos1 < 0) min_update(ans, get_dist(l2.a, l1.b));
	else if (cos2 < 0) min_update(ans, get_dist(l2.b, l1.b));
	else min_update(ans, get_vertical_dist(l2, l1.b));

	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed; cout.precision(20);

	int n, m; cin >> n >> m;
	vector<line> v1(n), v2(m);
	for (int i = 0; i < n; ++i) {
		double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		v1[i] = {{x1, y1}, {x2, y2}};
	}
	for (int i = 0; i < m; ++i) {
		double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		v2[i] = {{x1, y1}, {x2, y2}};
	}

	double ans = 99999999;
	for (auto& line1 : v1) for (auto& line2 : v2)
		ans = min(ans, get_minimum_dist(line1, line2));
	cout << ans;
}