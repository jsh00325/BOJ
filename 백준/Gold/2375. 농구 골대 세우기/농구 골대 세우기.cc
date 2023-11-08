#include <bits/stdc++.h>
using namespace std;
struct node { int x, y; };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, pSum = 0; cin >> n;
	vector<node> xc(n), yc(n);
	for (int i = 0; i < n; ++i) {
		int x, y, p; cin >> x >> y >> p;
		xc[i] = {x, p}, yc[i] = {y, p}, pSum += p;
	}
	sort(xc.begin(), xc.end(), [](node& a, node& b) { return a.x < b.x; });
	sort(yc.begin(), yc.end(), [](node& a, node& b) { return a.x < b.x; });

	int xCnt = 0, yCnt = 0, tar = (pSum - 1) / 2;
	for (auto curX : xc) if (tar < (xCnt += curX.y)) { cout << curX.x << ' '; break; }
	for (auto curY : yc) if (tar < (yCnt += curY.y)) { cout << curY.x; break; }
}