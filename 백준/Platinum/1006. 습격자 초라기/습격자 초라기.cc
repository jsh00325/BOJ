#include <bits/stdc++.h>
using namespace std;
inline void min_udt(int& tar, int val) { if (tar > val) tar = val; }

const int MX = 0x7fffffff;
int n, w, dp[10001][3], arr[2][10001];

void do_dp(int st_idx = 1) {
	memset(dp, 0, sizeof(dp));
	for (int i = st_idx; i <= n; ++i) {
		dp[i][0] = dp[i-1][2] + (arr[0][i] == MX ? 0 : 1);
		if (arr[0][i-1] + arr[0][i] <= w) min_udt(dp[i][0], dp[i-1][1]+1);

		dp[i][1] = dp[i-1][2] + (arr[1][i] == MX ? 0 : 1);
		if (arr[1][i-1] + arr[1][i] <= w) min_udt(dp[i][1], dp[i-1][0]+1);

		dp[i][2] = dp[i-1][2] + (arr[0][i] + arr[1][i] <= w ? 1 : (arr[0][i] <= w) + (arr[1][i] <= w));
		min_udt(dp[i][2], min(dp[i][0], dp[i][1]) + 1);
		if (i >= 2 && arr[0][i-1]+arr[0][i] <= w && arr[1][i-1]+arr[1][i] <= w) min_udt(dp[i][2], dp[i-2][2] + 2);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> n >> w;
		for (int i = 1; i <= n; ++i) cin >> arr[1][i];
		for (int i = 1; i <= n; ++i) cin >> arr[0][i];
		int ans = MX;

		// case 1
		do_dp(); min_udt(ans, dp[n][2]);

		// case 2
		if (arr[0][1] + arr[0][n] <= w) {
			int temp1 = arr[0][1], temp2 = arr[0][n];
			arr[0][1] = arr[0][n] = MX; 
			
			do_dp();
			min_udt(ans, dp[n][1] + 1);

			// case 4
			if (arr[1][1] + arr[1][n] <= w) {
				int temp3 = arr[1][1], temp4 = arr[1][n];
				arr[1][1] = arr[1][n] = MX; do_dp(2);
				min_udt(ans, dp[n-1][2] + 2);
				arr[1][1] = temp3, arr[1][n] = temp4;
			}
			arr[0][1] = temp1, arr[0][n] = temp2;
		}

		// case 3
		if (arr[1][1] + arr[1][n] <= w) {
			int temp1 = arr[1][1], temp2 = arr[1][n];
			arr[1][1] = arr[1][n] = MX; do_dp();
			min_udt(ans, dp[n][0] + 1);
			arr[1][1] = temp1, arr[1][n] = temp2;
		}

		cout << ans << '\n';
	}
}