#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

const int MX = 1e5;
int n, q; ll seg[2 * MX];

void update(int idx, int val) {
    for (seg[idx += n] = val; idx > 1; idx >>= 1)
        seg[idx >> 1] = seg[idx] + seg[idx ^ 1];
}
ll query(int l, int r) {
    ll ret = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    } return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    FOR(i, n) cin >> seg[i + n];
    for (int i = n - 1; i >= 0; --i) seg[i] = seg[i<<1] + seg[i<<1|1];

    int x, y, a, b;
    while (q--) {
        cin >> x >> y >> a >> b;
        cout << (x < y ? query(x - 1, y) : query(y - 1, x)) << '\n';
        update(a - 1, b);
    }
}