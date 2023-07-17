#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
typedef struct { int x, y; } node;

const int MX = 1000;
int n, m, arr[MX][MX], d[MX][MX];
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

inline bool oob(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
void bfs(int i, int j) {
    queue<node> q; 
    q.push({i, j}); d[i][j] = 0;
    while (!q.empty()) {
        node cur = q.front(); q.pop();
        FOR(dir, 4) {
            int ni = cur.x + di[dir], nj = cur.y + dj[dir];
            if (oob(ni, nj)) continue;
            if (arr[ni][nj] == 0) continue;
            if (d[ni][nj] != -1) continue;
            q.push({ni, nj}); d[ni][nj] = d[cur.x][cur.y] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; MEM(d, -1);
    FOR(i, n) FOR(j, m) cin >> arr[i][j];
    FOR(i, n) FOR(j, m)
        if (arr[i][j] == 2) bfs(i, j);
        else if (arr[i][j] == 0) d[i][j] = 0;
    FOR(i, n) { FOR(j, m) cout << d[i][j] << ' '; cout << '\n'; }
}