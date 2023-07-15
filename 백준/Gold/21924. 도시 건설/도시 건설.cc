#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)
typedef struct { int fr, to; ll w; } node;
struct cmp { bool operator()(const node& a, const node& b) { return a.w > b.w; } };

int n, m, a, b, c, cnt, p[100001];
ll all_sum, rslt;
priority_queue<node, vector<node>, cmp> pq;

int find(int x) {
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}
bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    p[y] = x; return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    FOR(i, m) {
        cin >> a >> b >> c, all_sum += c;
        pq.push({a, b, c});
    }

    FOR1(i, n) p[i] = i;
    
    while (!pq.empty()) {
        node cur = pq.top(); pq.pop();
        if (merge(cur.fr, cur.to)) {
            rslt += cur.w;
            if (++cnt == n - 1) break;
        }
    }

    if (cnt == n - 1) cout << all_sum - rslt;
    else cout << -1;
}