#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1), NONE = -1;
double dp[1500][1500];
string arr[700];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed; cout.precision(10);

	int h, w; cin >> h >> w;
	for (int i = 0; i < h; ++i) cin >> arr[i];

	// base condition
	for (int i = 1; i <= 2*h; ++i) dp[i][0] = dp[i-1][0] + 5;
	for (int j = 1; j <= 2*w; ++j) dp[0][j] = dp[0][j-1] + 5;
	for (int i = 1; i <= 2*h; ++i) for (int j = 1; j <= 2*w; ++j) dp[i][j] = NONE;

	for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
		if (arr[i][j] == 'X') {
			dp[2*i+2][2*j+2] = min(dp[2*i+2][2*j], dp[2*i][2*j + 2]) + 10;
		} else {
			if (dp[2*i+1][2*j] == NONE) dp[2*i+1][2*j] = dp[2*i][2*j] + 5;
			if (dp[2*i][2*j+1] == NONE) dp[2*i][2*j+1] = dp[2*i][2*j] + 5;
			dp[2*i+2][2*j+1] = min(dp[2*i+2][2*j] + 5, dp[2*i+1][2*j] + 2.5*PI);
			dp[2*i+1][2*j+2] = min(dp[2*i][2*j+2] + 5, dp[2*i][2*j+1] + 2.5*PI);
			dp[2*i+2][2*j+2] = min(dp[2*i+2][2*j+1], dp[2*i+1][2*j+2]) + 5;
		}
	} cout << dp[2*h][2*w];	
}