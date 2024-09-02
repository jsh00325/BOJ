#include <bits/stdc++.h>
using namespace std;

int dp[501][501], arr[501][501];

int main() {
	cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];
    
    for (int i = 1; i <= n; ++i) for (int j = 0; j < m; ++j) {
        int beforeMin = 0x7fffffff;
        for (int k = 0; k < m; ++k) if (k != j) 
            beforeMin = min(beforeMin, dp[i-1][k]);
        dp[i][j] = arr[i][j] + beforeMin;
    }

    int ans = 0x7fffffff;
    for (int i = 0; i < m; ++i) ans = min(ans, dp[n][i]);
    cout << ans;	
}