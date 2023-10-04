#include <bits/stdc++.h>
using namespace std;

int table[11][221][221];

int dp(int i, int j, int k) {
	int& curDP = table[i][j][k];
	if (curDP != -1) return curDP;

	if (i == 0 || k > j / i) return curDP = 0;
	if (i == 1) return curDP = (j == k);

	curDP = 0;
	for (int a = k; a <= (j - k) / (i - 1); ++a) curDP += dp(i-1, j-k, a);
	return curDP;
}

void solve(int n, int m, int st, int ord) {
	if (n == 1) {
		cout << m << ' ';
		return;
	}

	for (int i = st; i <= m / n; ++i) {
		if (dp(n, m, i) < ord) ord -= table[n][m][i];
		else {
			cout << i << ' ';
			solve(n-1, m-i, i, ord);
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, k; cin >> n >> m >> k;
	memset(table, -1, sizeof(table));
	solve(n, m, 1, k);
}