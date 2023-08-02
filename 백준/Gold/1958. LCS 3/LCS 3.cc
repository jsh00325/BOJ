#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

string s, t, u;
constexpr int di[3] = {-1, 0, 0}, dj[3] = {0, -1, 0}, dk[3] = {0, 0, -1};
int dp[101][101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> s >> t >> u;
    FOR1(i, s.size()) FOR1(j, t.size()) FOR1(k, u.size())
        if (s[i-1] == t[j-1] && t[j-1] == u[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        else FOR(dir, 3) dp[i][j][k] = max(dp[i][j][k], dp[i+di[dir]][j+dj[dir]][k+dk[dir]]);
    cout << dp[s.size()][t.size()][u.size()];
}