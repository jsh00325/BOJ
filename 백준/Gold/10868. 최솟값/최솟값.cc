#include <bits/stdc++.h>
using namespace std;
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)

const int MX = 1e5 + 3;
int n, m, a, b, h[MX], t[20][MX];

void build() {
	for (int i = 2; i <= n; i++) h[i] = h[i >> 1] + 1;
	int len = 1;
	for (int i = 1; i <= h[n]; i++) {
		for (int j = 1; j <= n - 2 * len + 1; j++)
			t[i][j] = min(t[i - 1][j], t[i - 1][j + len]);
		len <<= 1;
	}
}
int query(int st, int en) {
	int row = h[en - st + 1];
	return min(t[row][st], t[row][en - (1 << row) + 1]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR1(i, n) cin >> t[0][i]; build();
	FOR1(i, m) {
		cin >> a >> b;
		cout << query(a, b) << '\n';
	}
}