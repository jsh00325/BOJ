#include <bits/stdc++.h>
using namespace std;

const int MX = 2000000;
int t, x, seg[4*MX + 3];

int update(int node, int st, int en, int x, int val) {
    if (x < st || en < x) return seg[node];
    if (st == en) return seg[node] += val;
    int mid = (st + en) / 2;
    int lval = update(node << 1, st, mid, x, val);
    int rval = update((node << 1) + 1, mid+1, en, x, val);
    return seg[node] = lval + rval;
}

int query(int node, int st, int en, int k) {
    if (st == en) return st;
    int mid = (st + en) / 2;
    if (k <= seg[node << 1]) return query(node << 1, st, mid, k);
    else return query((node << 1) + 1, mid+1, en, k - seg[node << 1]);
}
int type2(int x) {
    int rslt = query(1, 1, MX, x);
    update(1, 1, MX, rslt, -1);
    return rslt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        cin >> t >> x;
        if (t == 1) update(1, 1, MX, x, 1);
        else cout << type2(x) << '\n';
    }
}