#include <bits/stdc++.h>

using namespace std;
const int MOD = 10007;
int dp[200007];

int solution(int n, vector<int> tops) {
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 2*(n+1); ++i) {
        if (i & 1) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
        else if (tops[(i >> 1) - 1]) {
            dp[i] = (2*dp[i-1] + dp[i-2]) % MOD;
        }
        else {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
    }
    return dp[2*n+1];
}