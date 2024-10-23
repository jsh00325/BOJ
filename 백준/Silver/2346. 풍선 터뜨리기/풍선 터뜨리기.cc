#include <bits/stdc++.h>
using namespace std;

typedef struct { int idx, val; } node;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    deque<node> d;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        d.push_back({i, x});
    }

    while (!d.empty()) {
        node cur = d.front(); d.pop_front();
        cout << cur.idx + 1 << ' ';

        if (cur.val > 0) {
            for (int i = 1; i < cur.val; ++i) {
                d.push_back(d.front());
                d.pop_front();
            }
        } else {
            for (int i = 0; i < -cur.val; ++i) {
                d.push_front(d.back());
                d.pop_back();
            } 
        }
    }
}