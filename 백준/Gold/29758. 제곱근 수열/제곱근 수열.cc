#include <bits/stdc++.h>
using namespace std;

int n, l, table[6][300], mx[6] = {0, 70000, 264, 16, 3, 1};

int dp(int i, int j) {
	if (i == 1) return (j == n);
	if (table[i][j] != -1) return table[i][j];
	
	table[i][j] = 0;
	for (int k = j*j + 1; k <= min(n, mx[i-1]); ++k) table[i][j] += dp(i-1, k);
	return table[i][j];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T; cin >> T;
	while (T--) {
		cin >> n >> l;
		memset(table, -1, sizeof(table));
		cout << (l > 5 ? 0 : dp(l, 1)) << '\n';
	}
}