#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5+3, POS_INF = 0x7fffffff, NEG_INF = 0;
int n, m, minSeg[4*MX], maxSeg[4*MX];

void min_build(int node, int l, int r, vector<int> &v) {
    if (l == r) {
        minSeg[node] = v[l];
        return;
    }

    int mid = (l + r) >> 1, lc = node << 1, rc = lc + 1;
    min_build(lc, l, mid, v);
    min_build(rc, mid+1, r, v);
    minSeg[node] = min(minSeg[lc], minSeg[rc]);
}

void max_build(int node, int l, int r, vector<int> &v) {
    if (l == r) {
        maxSeg[node] = v[l];
        return;
    }

    int mid = (l + r) >> 1, lc = node << 1, rc = lc + 1;
    max_build(lc, l, mid, v);
    max_build(rc, mid+1, r, v);
    maxSeg[node] = max(maxSeg[lc], maxSeg[rc]);
}

int min_query(int node, int l, int r, int st, int en) {
    if (en < l || r < st) return POS_INF;
    if (st <= l && r <= en) return minSeg[node];

    int mid = (l + r) >> 1, lc = node << 1, rc = lc + 1;
    int lval = min_query(lc, l, mid, st, en);
    int rval = min_query(rc, mid+1, r, st, en);

    return min(lval, rval);
}

int max_query(int node, int l, int r, int st, int en) {
    if (en < l || r < st) return NEG_INF;
    if (st <= l && r <= en) return maxSeg[node];

    int mid = (l + r) >> 1, lc = node << 1, rc = lc + 1;
    int lval = max_query(lc, l, mid, st, en);
    int rval = max_query(rc, mid+1, r, st, en);

    return max(lval, rval);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    min_build(1, 0, n-1, v);
    max_build(1, 0, n-1, v);

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        cout << min_query(1, 0, n-1, a-1, b-1) << ' ';
        cout << max_query(1, 0, n-1, a-1, b-1) << '\n';
    }
}