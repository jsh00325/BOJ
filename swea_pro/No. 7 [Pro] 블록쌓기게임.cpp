#include <bits/stdc++.h>
#define FOR(i, n) for (register int (i) = 0; (i) < (n); (i)++)
#define L node << 1
#define R node << 1 | 1
using namespace std;
constexpr int MX = 1e6, MOD = 1e6;
 
struct Result { int top, count; };
int c, cnt;
int mnSeg[4 * MX], mxSeg[4 * MX], lz[4 * MX];
 
void lazy(int node, int l, int r) {
    if (lz[node]) {
        mnSeg[node] += lz[node];
        mxSeg[node] += lz[node];
        if (l != r) {
            lz[L] += lz[node];
            lz[R] += lz[node];
        }
        lz[node] = 0;
    }
}
 
void update(int node, int l, int r, int st, int en, int val) {
    lazy(node, l, r);
    if (r < st || en < l) return;
    if (st <= l && r <= en) {
        lz[node] += val;
        lazy(node, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(L, l, mid, st, en, val);
    update(R, mid + 1, r, st, en, val);
    mnSeg[node] = min(mnSeg[L], mnSeg[R]);
    mxSeg[node] = max(mxSeg[L], mxSeg[R]);
}
 
void init(int C) {
    c = C; cnt = 0;
    memset(mnSeg, 0, sizeof(mnSeg));
    memset(mxSeg, 0, sizeof(mxSeg));
    memset(lz, 0, sizeof(lz));
}
 
Result dropBlocks(int mCol, int mHeight, int mLength) {
    update(1, 0, c - 1, mCol, mCol + mLength - 1, mHeight);
    cnt = (cnt + mHeight * mLength) % MOD;
    cnt = (cnt + MOD - (mnSeg[1] * c) % MOD) % MOD;
    lz[1] -= mnSeg[1];
    return { mxSeg[1] - mnSeg[1], cnt };
}