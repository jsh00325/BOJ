#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define REV_FOR(i, n) for(int (i) = (n) - 1; (i) >= 0; --i)
typedef struct { int bit, count; } node;

int n, k; bool vst[1<<24];

int bit_swap(int src, int i, int j) {
    int ans = 0, temp[8];
    FOR(k, n) temp[k] = src & 7, src >>= 3;
    swap(temp[i], temp[j]);
    REV_FOR(k, n) ans = (ans << 3) | temp[k];
    return ans;    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    int x, cur_bit = 0, ans_bit = 0;
    FOR(i, n) cin >> x, cur_bit = (cur_bit << 3) | (x - 1), ans_bit = (ans_bit << 3) | i;
    queue<node> q; q.push({cur_bit, 0}); vst[cur_bit] = true;
    while (!q.empty()) {
        node cur = q.front(); q.pop();
        if (cur.bit == ans_bit) { cout << cur.count; return 0; }
        FOR(st, n - k + 1) {
            int nxt = cur.bit;
            FOR(d, k >> 1) nxt = bit_swap(nxt, st + d, st + k - d - 1);
            if (vst[nxt]) continue;
            q.push({nxt, cur.count + 1}); vst[nxt] = true;
        }
    } cout << -1;
}