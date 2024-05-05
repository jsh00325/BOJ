#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5+7;
int n, k, arr[MX], maxSeg[4*MX], minSeg[4*MX];

const int MIN_INIT = 0x7fffffff, MAX_INIT = -1;

int maxFunc(int& a, int& b) { return (a > b ? a : b); }
int minFunc(int& a, int& b) { return (a < b ? a : b); }

int update(int seg[], int idx, int st, int en, int tar, int val, int (*fun)(int&, int&)) {
    if (tar < st || en < tar) return seg[idx];
    if (st == en) return seg[idx] = val;
    
    int mid = (st + en) >> 1;
    int lv = update(seg, idx << 1, st, mid, tar, val, fun);
    int rv = update(seg, (idx << 1) + 1, mid+1, en, tar, val, fun);
    return seg[idx] = fun(lv, rv);
}

int query(int seg[], int idx, int st, int en, int l, int r, int initValue, int (*fun)(int&, int&)) {
    if (l <= st && en <= r) return seg[idx];
    if (r < st || en < l) return initValue;

    int mid = (st + en) >> 1;
    int lValue = query(seg, (idx<<1), st, mid, l, r, initValue, fun);
    int rValue = query(seg, (idx<<1)+1, mid+1, en, l, r, initValue, fun);
    return fun(lValue, rValue);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        
        for (int i = 0; i < 4*MX; ++i) {
            minSeg[i] = MIN_INIT, maxSeg[i] = MAX_INIT;
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
            update(minSeg, 1, 0, n-1, i, i, minFunc);
            update(maxSeg, 1, 0, n-1, i, i, maxFunc);
        }

        while (k--) {
            int o, a, b; cin >> o >> a >> b;
            if (o == 0) {   // chanege
                swap(arr[a], arr[b]);
                update(minSeg, 1, 0, n-1, a, arr[a], minFunc);
                update(minSeg, 1, 0, n-1, b, arr[b], minFunc);
                update(maxSeg, 1, 0, n-1, a, arr[a], maxFunc);
                update(maxSeg, 1, 0, n-1, b, arr[b], maxFunc);
            }
            else {  // query
                int minValue = query(minSeg, 1, 0, n-1, a, b, 0x7fffffff, minFunc);
                int maxValue = query(maxSeg, 1, 0, n-1, a, b, -1, maxFunc);

                cout << (minValue == a && maxValue == b ? "YES" : "NO") << '\n';
            }
        }
    }
}