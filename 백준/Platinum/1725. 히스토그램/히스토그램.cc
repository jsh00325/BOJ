#include <bits/stdc++.h>
using namespace std;
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

const int MX = 100003, INF = 0x7fffffff;
int n, arr[MX], seg[4*MX];

int build(int node, int st, int en) {
    if (st == en) return seg[node] = st;
    int mid = (st + en) / 2;
    int lidx = build(node<<1, st, mid), ridx = build((node<<1)+1, mid+1, en);
    return seg[node] = (arr[lidx] < arr[ridx] ? lidx : ridx);
}

int query(int node, int st, int en, int l, int r) {
    if (en < l || r < st) return 0;
    if (l <= st && en <= r) return seg[node];
    int mid = (st + en) / 2;
    int lidx = query(node<<1, st, mid, l, r), ridx = query((node<<1)+1, mid+1, en, l, r);
    return (arr[lidx] < arr[ridx] ? lidx : ridx);
}

int solve(int l, int r) {
    if (l > r) return 0;
    if (l == r) return arr[l];
    int mn_idx = query(1, 1, n, l, r);
    int ret = (r - l + 1) * arr[mn_idx];
    int lval = solve(l, mn_idx - 1);
    int rval = solve(mn_idx + 1, r);
    if (ret < lval) ret = lval;
    if (ret < rval) ret = rval;
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    arr[0] = INF;
    FOR1(i, n) cin >> arr[i];
    build(1, 1, n);
    cout << solve(1, n);
}