#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
typedef struct { int x, y; } node;

int n, m, ans, di[4] = {0,1,0,-1}, dj[4] = {1,0,-1,0};
bool visit[600][600];
string arr[600];

inline bool oob(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    FOR(i, n) cin >> arr[i];
    FOR(i, n) FOR(j, m) if (arr[i][j] == 'I') {
        queue<node> q; 
        q.push({i, j}); visit[i][j] = true;
        while (!q.empty()) {
            node cur = q.front(); q.pop();
            if (arr[cur.x][cur.y] == 'P') ans++;
            FOR(dir, 4) {
                int ni = cur.x + di[dir], nj = cur.y + dj[dir];
                if (oob(ni ,nj)) continue;
                if (arr[ni][nj] == 'X' || visit[ni][nj]) continue;
                q.push({ni, nj}); visit[ni][nj] = true;
            }

        }
        if (ans) cout << ans;
        else cout << "TT";
        return 0;
    }
}