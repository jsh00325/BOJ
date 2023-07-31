#include <bits/stdc++.h>
using namespace std;

int dp[31];
int solve(int n) {
	if (n % 2) return 0;

	dp[0] = 1; dp[2] = 3;
	for (int i = 4; i <= n; i += 2)
		for (int uni = 2; uni <= i; uni += 2)
			dp[i] += (uni == 2 ? 3 : 2) * dp[i - uni];
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	cout << solve(n);
}