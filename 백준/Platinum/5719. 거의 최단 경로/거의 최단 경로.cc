#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

struct vertex {
	int from, to, w;
	bool isdead;
};
const int INF = 0x3ffffff;
int n, m, s, e, d[500];
vertex ver_arr[10000];
vector<int> prv_ver[500], edge[500];
priority_queue<pii> pq;

void cut_ver(int idx) {
	vertex& cur = ver_arr[idx];
	if (cur.isdead) return;
	cur.isdead = true;
	for (int nxt : prv_ver[cur.from]) cut_ver(nxt);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> s >> e;
		for (int i = 0; i < m; i++) {
			cin >> ver_arr[i].from >> ver_arr[i].to >> ver_arr[i].w;
			ver_arr[i].isdead = false;
			edge[ver_arr[i].from].push_back(i);
		}

		// 경로를 기록하는 다익
		fill(d, d + n, INF);
		d[s] = 0; pq.push({ d[s], s });
		while (!pq.empty()) {
			pii cur = pq.top(); pq.pop();
			if (d[cur.Y] != cur.X) continue;

			for (int v_idx : edge[cur.Y]) {
				vertex& nxt = ver_arr[v_idx];
				if (d[nxt.to] > cur.X + nxt.w) {
					prv_ver[nxt.to].clear();
					d[nxt.to] = cur.X + nxt.w;
					pq.push({ d[nxt.to], nxt.to });
					prv_ver[nxt.to].push_back(v_idx);
				}
				else if (d[nxt.to] == cur.X + nxt.w) {
					prv_ver[nxt.to].push_back(v_idx);
				}
			}
		}
		// 최단경로를 이루는 간선 삭제
		for (int idx : prv_ver[e]) cut_ver(idx);

		fill(d, d + n, INF);
		d[s] = 0; pq.push({ d[s], s });
		while (!pq.empty()) {
			pii cur = pq.top(); pq.pop();
			if (d[cur.Y] != cur.X) continue;
			for (int nxt_idx : edge[cur.Y]) {
				vertex& nxt = ver_arr[nxt_idx];
				if (nxt.isdead) continue;
				if (d[nxt.to] > cur.X + nxt.w) {
					d[nxt.to] = cur.X + nxt.w;
					pq.push({ d[nxt.to], nxt.to });
				}
			}
		}
		cout << (d[e] == INF ? -1 : d[e]) << '\n';

		for (int i = 0; i < n; i++) {
			prv_ver[i].clear();
			edge[i].clear();
		}
	}
}