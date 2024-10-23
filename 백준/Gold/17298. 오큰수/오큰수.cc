#include <bits/stdc++.h>
using namespace std;

typedef struct { int idx, val; } node;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> rslt(n, -1);

    stack<node> s;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (s.empty() || s.top().val > x) s.push({i, x});
        else {
            while (!s.empty() && s.top().val < x) {
                node cur = s.top(); s.pop();
                rslt[cur.idx] = x;
            }
            s.push({i, x});
        }
    }

    for (int i : rslt) cout << i << ' ';
}