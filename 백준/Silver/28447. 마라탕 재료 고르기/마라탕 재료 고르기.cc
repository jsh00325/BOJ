#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

int n, k, c[10][10];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    FOR(i, n) FOR(j, n) cin >> c[i][j];
    int ans = -999999999;
    FOR(bit, (1 << n)) {
        vector<int> v; int sum = 0;
        FOR(i, n) if (bit & (1 << i)) v.push_back(i);
        if (v.size() == k) {
            FOR(i, v.size()) for (int j = i + 1; j < v.size(); j++)
                sum += c[v[i]][v[j]];
            if (ans < sum) ans = sum;
        }
    }
    cout << ans;
}