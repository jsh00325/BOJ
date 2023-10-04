#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	double x, y, c; cin >> x >> y >> c;
	double st = 0, en = max(x, y);
	while (st + 0.001 < en) {
		double mid = (st + en) / 2;
		double h1 = sqrt(x*x - mid*mid), h2 = sqrt(y*y - mid*mid);
		double curC = h1 * h2 / (h1 + h2), diff = c - curC;

		if (diff < 0) st = mid;
		else en = mid;
	} cout << st;
}