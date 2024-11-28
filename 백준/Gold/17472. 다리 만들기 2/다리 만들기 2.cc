#include <bits/stdc++.h>
using namespace std;

struct node { int a, b, c; };
const int INF = 0x7fffffff;
int h, w, v, arr[10][10], islandNumber[10][10], adj[10][10], p[10];
bool vst[10][10];

inline bool _oob(int i, int j) { return i < 0 || j < 0 || i >= h || j >= w; }
bool cmp(node &a, node &b) { return a.c < b.c; }
void findIsland();
vector<node> getEdge();
int getMST(vector<node> &edge);
void _dfs(int i, int j, int value);
void _makeBridge(int i, int j, int dir);
int _find(int x);
bool _merge(int x, int y);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> h >> w;
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) cin >> arr[i][j];
    
    findIsland();
    vector<node> edge = getEdge();
    cout << getMST(edge);
}

void findIsland() {
    memset(vst, 0, sizeof(vst)); v = 0;
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j)
        if (arr[i][j] && !vst[i][j]) _dfs(i, j, ++v);
}

vector<node> getEdge() {
    for (int i = 1; i <= v; ++i) for (int j = 1; j <= v; ++j) adj[i][j] = INF;
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) if (arr[i][j]) {
        for (int dir = 0; dir < 4; ++dir) _makeBridge(i, j, dir);
    }

    vector<node> edge;
    for (int i = 1; i <= v; ++i) for (int j = i+1; j <= v; ++j) if (adj[i][j] != INF)
        edge.push_back({i, j, adj[i][j]});
    return edge;
}

int getMST(vector<node> &edge) {
    sort(edge.begin(), edge.end(), cmp);
    memset(p, -1, sizeof(p));

    int cnt = 0, ans = 0;
    for (auto &e : edge) if (_merge(e.a, e.b)) {
        ans += e.c;
        if (++cnt == v-1) break;
    }
    return (cnt == v-1 ? ans : -1); 
}

void _dfs(int i, int j, int value) {
    vst[i][j] = 1, islandNumber[i][j] = value;
    for (int dir = 0; dir < 4; ++dir) {
        int ni = i + ("1012"[dir] - '1'), nj = j + ("0121"[dir] - '1');
        if (_oob(ni, nj) || !arr[ni][nj] || vst[ni][nj]) continue;
        _dfs(ni, nj, value);
    }
}

void _makeBridge(int i, int j, int dir) {
    int originIsland = islandNumber[i][j], bridgeDist = 0;

    for (int bridgeDist = 0; ; ++bridgeDist) {
        i += ("1012"[dir] - '1'), j += ("0121"[dir] - '1');
        if (_oob(i, j)) break;
        if (!arr[i][j]) continue;

        int curIsland = islandNumber[i][j];
        if (curIsland == originIsland) break;
        if (bridgeDist < 2) break;

        adj[originIsland][curIsland] = min(bridgeDist, adj[originIsland][curIsland]);
        adj[curIsland][originIsland] = adj[originIsland][curIsland];
        break;
    }
}

int _find(int x) {
    if (p[x] < 0) return x;
    else return p[x] = _find(p[x]);
}

bool _merge(int x, int y) {
    x = _find(x), y = _find(y);
    if (x == y) return false;

    if (p[x] < p[y]) p[x] += p[y], p[y] = x;
    else p[y] += p[x], p[x] = y;
    return true;
}