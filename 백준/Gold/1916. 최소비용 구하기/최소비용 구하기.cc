#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, m, d[1001], st, en;
vector<pii> edge[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b, w; cin >> a >> b >> w;
		edge[a].push_back({ b, w });
	}
	cin >> st >> en;

	fill(d + 1, d + n + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	d[st] = 0; pq.push({ 0, st });

	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();

		if (d[cur.Y] != cur.X) continue;

		for (pii nxt : edge[cur.Y]) {
			if (d[nxt.X] > cur.X + nxt.Y) {
				d[nxt.X] = cur.X + nxt.Y;
				pq.push({ d[nxt.X], nxt.X });
			}
		}
	}
	cout << d[en];
}