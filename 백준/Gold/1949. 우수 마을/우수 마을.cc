#include <bits/stdc++.h>
using namespace std;
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)
typedef struct { int x, y; } node;

const int MX = 10001;
int n, dp[MX][2];
bool visit[MX];
vector<int> edge[MX];

void tree_dp(int cur) {
    if (visit[cur]) return;
    visit[cur] = true;
    for (int& nxt : edge[cur]) if (!visit[nxt]) {
        tree_dp(nxt);
        dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    FOR1(i, n) cin >> dp[i][1];
    FOR1(i, n-1) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    tree_dp(1);
    cout << max(dp[1][0], dp[1][1]);
}