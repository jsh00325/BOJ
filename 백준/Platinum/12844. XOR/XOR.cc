#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

const int MX = 500003;
int n, m, cmd, i, j, k, arr[MX], seg[4*MX], lazy[4*MX];

int build(int node, int st, int en) {
    if (st == en) return seg[node] = arr[st];
    int mid = (st + en) / 2;
    int leftVal = build(node << 1, st, mid);
    int rightVal = build((node << 1) + 1, mid + 1, en);
    return seg[node] = leftVal ^ rightVal;
}

void lazyUpdate(int node, int st, int en) {
    if (lazy[node]) {
        if ((en - st + 1) & 1) seg[node] ^= lazy[node];
        if (st != en) lazy[node << 1] ^= lazy[node], lazy[(node << 1) + 1] ^= lazy[node];
        lazy[node] = 0;
    }
}

int update(int node, int st, int en, int l, int r, int val) {
    lazyUpdate(node, st, en);
    if (en < l || r < st) return seg[node];
    if (l <= st && en <= r) {
        lazy[node] ^= val;
        lazyUpdate(node, st, en);
        return seg[node];
    }
    int mid = (st + en) / 2;
    int leftVal = update(node << 1, st, mid, l, r, val);
    int rightVal = update((node << 1) + 1, mid + 1, en, l, r, val);
    return seg[node] = leftVal ^ rightVal;
}

int query(int node, int st, int en, int l, int r) {
    lazyUpdate(node, st, en);
    if (en < l || r < st) return 0;
    if (l <= st && en <= r) return seg[node];
    int mid = (st + en) / 2;
    int leftVal = query(node << 1, st, mid, l, r);
    int rightVal = query((node << 1) + 1, mid + 1, en, l, r);
    return leftVal ^ rightVal;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n; FOR(i, n) cin >> arr[i];
    build(1, 0, n-1);
    cin >> m; FOR(q, m) {
        cin >> cmd;
        if (cmd == 1) cin >> i >> j >> k, update(1, 0, n-1, i, j, k);
        else cin >> i >> j, cout << query(1, 0, n-1, i, j) << '\n';
    }
}