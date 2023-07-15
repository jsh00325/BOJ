#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)
typedef struct { string cur; int cnt; } node;

/*
0 1 2
3 4 5
6 7 8
*/

int n, di[4] = { 0, 0, -1, 1 }, dj[4] = { -1, 1, 0, 0 };
string arr = "000000000";
unordered_set<string> visit;
queue<node> q;

inline bool oob(int i, int j) {return i < 0 || i >= 3 || j < 0 || j >= 3;}
int zero_index(const string& s) {
    FOR(i, 9) if (s[i] == '0') return i;
    return -1;
}
string move(const string& s, int i1, int j1, int i2, int j2) {
    string ret = s;
    swap(ret[i1 * 3 + j1], ret[i2 * 3 + j2]);
    return ret;
}
int solve() {
    q.push({arr, 0}); visit.insert(arr);
    while (!q.empty()) {
        node cur = q.front(); q.pop();
        if (cur.cur == "123456780") return cur.cnt;
        int zi = zero_index(cur.cur);
        int ci = zi / 3, cj = zi % 3;
        FOR(dir, 4) {
            int ni = ci + di[dir], nj = cj + dj[dir];
            if (oob(ni, nj)) continue;
            string nxt = move(cur.cur, ci, cj, ni, nj);
            if (visit.find(nxt) != visit.end()) continue;
            q.push({nxt, cur.cnt+1}); visit.insert(nxt);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    FOR(i, 9) cin >> n, arr[i] += n;
    cout << solve();

}