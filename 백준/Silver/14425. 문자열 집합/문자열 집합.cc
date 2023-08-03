#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string str; int n, m, ans = 0; cin >> n >> m;
    unordered_set<string> s;
    FOR(i, n) cin >> str, s.insert(str);
    FOR(i, m) cin >> str, ans += (s.find(str) != s.end());
    cout << ans;
}