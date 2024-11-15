#include <bits/stdc++.h>
using namespace std;

const int MX = 1003;
bool edge[MX][MX], vst[MX];

void dfs(int n, int cur) {
    vst[cur] = 1;
    cout << cur << ' ';
    for (int nxt = 1; nxt <= n; ++nxt) if (!vst[nxt] && edge[cur][nxt]) {
        dfs(n, nxt);
    }
}

void bfs(int n, int st) {
    queue<int> q;
    q.push(st); vst[st] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int nxt = 1; nxt <= n; ++nxt) if (!vst[nxt] && edge[cur][nxt]) {
            q.push(nxt); vst[nxt] = 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, v; cin >> n >> m >> v;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        edge[u][v] = edge[v][u] = 1;
    }

    dfs(n, v); cout << '\n';
    memset(vst, 0, sizeof(vst));
    bfs(n, v);
}