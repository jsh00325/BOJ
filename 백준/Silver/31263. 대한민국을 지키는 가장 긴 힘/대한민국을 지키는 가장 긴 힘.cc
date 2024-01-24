#include <bits/stdc++.h>
using namespace std;

int n, dp[5001];
string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;

	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; ++i) {
		dp[i] = i;
		if (s[i-1] != '0') dp[i] = min(dp[i], dp[i-1] + 1);
		if (s[i-2] != '0') dp[i] = min(dp[i], dp[i-2] + 1);
		if (s[i-3] != '0' && (s[i-3]-'0')*100 + (s[i-2]-'0')*10 + (s[i-1]-'0') <= 641) dp[i] = min(dp[i], dp[i-3] + 1);
	} cout << dp[n];
}