#include <bits/stdc++.h>
using namespace std;

struct node { int u, v, c; };
const int MX = 1e4+3;
int p[MX];

bool msort(node& a, node& b) {
    return a.c < b.c;
}

int find(int x) {
    if (p[x] < 0) return x;
    else return p[x] = find(p[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (p[x] < p[y]) p[x] += p[y], p[y] = x;
    else p[y] += p[x], p[x] = y;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int v, e; cin >> v >> e;
    vector<node> edge(e);
    for (auto &i : edge) cin >> i.u >> i.v >> i.c;
    sort(edge.begin(), edge.end(), msort);
    
    memset(p, -1, sizeof(p));
    int ans = 0, cnt = 0;
    for (auto cur : edge) {
        if (merge(cur.u, cur.v)) {
            ans += cur.c;
            if (++cnt == v-1) break;
        }
    }
    cout << ans;
}