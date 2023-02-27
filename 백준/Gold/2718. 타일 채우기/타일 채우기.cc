#include <bits/stdc++.h>
using namespace std;

int dp[22];
int uniq(int x) {
	if (x == 1) return 1;
	if (x == 2) return 4;
	return x % 2 ? 2 : 3;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[1] = 1;
	for (int i = 2; i < 22; i++) {
		dp[i] = uniq(i);
		for (int j = i - 1; j >= 1; j--)
			dp[i] += uniq(j) * dp[i - j];
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
}