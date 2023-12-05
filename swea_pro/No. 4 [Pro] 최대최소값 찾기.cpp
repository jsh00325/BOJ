#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (register int (i) = 0; (i) < (n); ++(i))
 
constexpr int MX = 200000, MN_FLAG = 0x7fffffff, MX_FLAG = -1;
int mnTree[2 * MX], mxTree[2 * MX], cnt, en, realIdx[MX];
 
void mnUpdate(int idx, int val) {
    for (mnTree[idx += MX] = val; idx > 1; idx >>= 1)
        mnTree[idx >> 1] = min(mnTree[idx], mnTree[idx ^ 1]);
}
void mxUpdate(int idx, int val) {
    for (mxTree[idx += MX] = val; idx > 1; idx >>= 1)
        mxTree[idx >> 1] = max(mxTree[idx], mxTree[idx ^ 1]);
}
 
int mnQuery(int l, int r) {
    register int res = MN_FLAG;
    for (l += MX, r += MX; l < r; l >>= 1, r >>= 1) {
        if (l & 1 && res > mnTree[l++]) res = mnTree[l - 1];
        if (r & 1 && res > mnTree[--r]) res = mnTree[r];
    } return res;
}
 
int mxQuery(int l, int r) {
    register int res = MX_FLAG;
    for (l += MX, r += MX; l < r; l >>= 1, r >>= 1) {
        if (l & 1 && res < mxTree[l++]) res = mxTree[l - 1];
        if (r & 1 && res < mxTree[--r]) res = mxTree[r];
    } return res;
}
 
void init(int N, int mValue[]) {
    cnt = en = N;
    FOR(i, N) mnTree[i + MX] = mxTree[i + MX] = mValue[i];
    for (register int i = N + MX; i < 2 * MX; ++i) mnTree[i] = MN_FLAG, mxTree[i] = MX_FLAG;
    for (register int i = MX - 1; i > 0; --i) {
        mnTree[i] = min(mnTree[i << 1], mnTree[i << 1 | 1]);
        mxTree[i] = max(mxTree[i << 1], mxTree[i << 1 | 1]);
    }
    FOR(i, MX) realIdx[i] = i;
}
 
void add(int M, int mValue[]) {
    FOR(i, M) {
        mnUpdate(en, mValue[i]);
        mxUpdate(en, mValue[i]);
        realIdx[cnt++] = en++;
    }
}
 
void erase(int mFrom, int mTo) {
    mFrom--, mTo--;
    for (register int cur = mFrom; cur <= mTo; ++cur) {
        mnUpdate(realIdx[cur], MN_FLAG);
        mxUpdate(realIdx[cur], MX_FLAG);
        cnt--;
    }
    register int diff = mTo - mFrom + 1;
    for (register int cur = mFrom; cur < cnt; ++cur) realIdx[cur] = realIdx[cur + diff];
}
 
int find(int K) {
    return mxQuery(realIdx[cnt - K], realIdx[cnt - 1] + 1) - mnQuery(realIdx[cnt - K], realIdx[cnt - 1] + 1);
}