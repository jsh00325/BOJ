#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

struct INFO {
	int chge, tme;

	bool operator!= (const INFO& other) {
		return this->chge != other.chge || this->tme != other.tme;
	}
	bool operator> (const INFO& other) {
		if (this->chge == other.chge) return this->tme > other.tme;
		else return this->chge > other.chge; 
	}
} dist[1000];
struct pqNode {
	int cur;
	INFO infomation;
};
struct cmp { bool operator() (const pqNode& x, const pqNode& y) {
	const INFO& a = x.infomation, &b = y.infomation;
	if (a.chge == b.chge) return a.tme > b.tme;
	else return a.chge > b.chge;
} };

const int INF = 0x3f3f3f3f;
int n, m, type[1000], edge[1000][1000];
priority_queue<pqNode, vector<pqNode>, cmp> pq;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR(i, n) cin >> type[i];
	FOR(i, n) FOR(j, n) cin >> edge[i][j];

	FOR(i, n) dist[i] = {INF, INF};
	dist[0] = {0, 0}; pq.push({0, {0, 0}});

	while (!pq.empty()) {
		int cur = pq.top().cur;
		INFO curInfo = pq.top().infomation;
		pq.pop();

		if (dist[cur] != curInfo) continue;
		if (cur == m) break;

		FOR(nxt, n) if (edge[cur][nxt]) {
			INFO nxtInfo = {curInfo.chge, curInfo.tme + edge[cur][nxt]};
			if (type[cur] != type[nxt]) ++nxtInfo.chge;

			if (dist[nxt] > nxtInfo) {
				dist[nxt] = nxtInfo;
				pq.push({nxt, nxtInfo});
			}
		}
	}
	cout << dist[m].chge << ' ' << dist[m].tme;
}