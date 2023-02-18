#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
#define X first
#define Y second

pii st, en, lv;
const int INF = 0x3fffffff;
int r, c, d[103][103];
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

inline bool oob(pii x) { return x.X < 0 || x.X >= r || x.Y < 0 || x.Y >= c; }
void find_loc(const vector<string> &m) {
    r = m.size(); c = m[0].size();
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (m[i][j] == 'S') st = {i, j};
            else if (m[i][j] == 'E') en = {i, j};
            else if (m[i][j] == 'L') lv = {i, j};
}
void dijkstra(pii x, const vector<string> &m) {
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) d[i][j] = INF;
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    d[x.X][x.Y] = 0; pq.push({0, x});
    while (!pq.empty()) {
        int cur_d = pq.top().X;
        pii cur_l = pq.top().Y;
        pq.pop();
        if (d[cur_l.X][cur_l.Y] != cur_d) continue;
        for (int dir = 0; dir < 4; dir++) {
            pii nxt = {cur_l.X + di[dir], cur_l.Y + dj[dir]};
            if (oob(nxt)) continue;
            if (m[nxt.X][nxt.Y] == 'X') continue;
            if (d[nxt.X][nxt.Y] <= cur_d + 1) continue;
            d[nxt.X][nxt.Y] = cur_d + 1;
            pq.push({d[nxt.X][nxt.Y], nxt});
        }
    }
}

int solution(vector<string> m) {
    find_loc(m);
    dijkstra(lv, m);
    
    if (d[st.X][st.Y] == INF || d[en.X][en.Y] == INF) return -1;
    return d[st.X][st.Y] + d[en.X][en.Y];
}