#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)

int n, m, x, arr[21][301], dp[21][301], from[21][301];

void tracking(int i, int j) {
	if (i == 0) return;
	tracking(i - 1, from[i][j]);
	cout << j - from[i][j] << ' ';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR1(i, n) { cin >> x; FOR1(j, m) cin >> arr[j][i]; }
	FOR1(i, m) FOR1(j, n) FOR(k, j + 1)
		if (dp[i][j] < dp[i - 1][k] + arr[i][j - k]) {
			dp[i][j] = dp[i - 1][k] + arr[i][j - k];
			from[i][j] = k;
		}
	cout << dp[m][n] << '\n';
	tracking(m, n);
}