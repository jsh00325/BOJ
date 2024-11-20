#include <bits/stdc++.h>
using namespace std;

typedef struct { int u, v, p; } node;
const int MX = 1e5 + 3;
vector<node> edge[MX];

bool compare(node &a, node &b) { return a.p < b.p; }

int p[MX];

int find(int x) {
    if (p[x] == -1) return x;
    else return p[x] = find(p[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    else {
        p[y] = x;
        return true;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<node> edge(m);
    for (auto &x : edge) cin >> x.u >> x.v >> x.p;
    sort(edge.begin(), edge.end(), compare);

    int ans = 0, cnt = 0;
    memset(p, -1, sizeof(p));
    for (auto cur : edge) {
        if (cnt == n-2) break;
        if (merge(cur.u, cur.v)) ans += cur.p, ++cnt;
    }
    cout << ans;
}