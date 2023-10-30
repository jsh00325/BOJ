#include <bits/stdc++.h>
using namespace std;
struct node { int x, y; };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<node> v(n);
	vector<bool> check(n);
	for (int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y;
	sort(v.begin(), v.end(), [](const node& a, const node& b) { return a.x < b.x; });

	int prev1 = -9999999, prev2 = 9999999;
	for (int i = 0; i < n; ++i) {
		if (v[i].y > prev1) prev1 = v[i].y;
		else check[i] = true;
	}
	for (int i = n-1; i >= 0; --i) {
		if (v[i].y < prev2) prev2 = v[i].y;
		else check[i] = true;
	}
	int count = 0;
	for (auto x : check) count += (!x);
	cout << count;
}