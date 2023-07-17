#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

const int MX = 30000;
int n, m, k, a, b, p[MX+1], c[MX+1], sm[MX+1], dp[3000];

int find(int x) {
    if (p[x] < 0) return x;
    else return p[x] = find(p[x]);
}
bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (p[x] < p[y]) p[x] += p[y], p[y] = x, c[x] += c[y];
    else p[y] += p[x], p[x] = y, c[y] += c[x];
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    FOR1(i, n) cin >> c[i];
    MEM(p, -1);
    FOR1(i, m) cin >> a >> b, merge(a, b);

    FOR1(i, n) if (p[i] < 0) for (int j = k-1; j >= -p[i]; j--)
        if (dp[j] < dp[j+p[i]] + c[i]) dp[j] = dp[j+p[i]] + c[i];
    cout << dp[k-1];
}