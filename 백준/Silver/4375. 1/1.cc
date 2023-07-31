#include <bits/stdc++.h>
using namespace std;

int solve(int p) {
    int cur = 1;
    for (int ans = 1; ; ans++)
        if (cur % p == 0) return ans;
        else cur = (10 * cur + 1) % p;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int x; while (cin >> x) cout << solve(x) << '\n';
}