#include <bits/stdc++.h>
using namespace std;

int n, m, arr[1030][1030], seg[1030][1030];

void update(int i, int j, int delta) {
	for (int r = i; r <= n; r += (r & -r))
		for (int c = j; c <= n; c += (c & -c))
			seg[r][c] += delta;
	arr[i][j] += delta;
}

int query(int i, int j) {
	int ans = 0;
	for (int r = i; r > 0; r -= (r & -r))
		for (int c = j; c > 0; c -= (c & -c))
			ans += seg[r][c];
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		int x; cin >> x;
		update(i, j, x);
	}

	while (m--) {
		int q; cin >> q;
		if (q == 0) {
			int i, j, x; cin >> i >> j >> x;
			update(i, j, x-arr[i][j]);
		}
		else {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			cout << query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1) << '\n';
		}
	}
}