#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

struct NODE {
	int prv, nxt;
} node[1000001];

int n, m, i, j;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	vector<int> v(n); FOR(i, n) cin >> v[i];
	FOR(i, n) node[v[i]].prv = v[(i+n-1)%n], node[v[i]].nxt = v[(i+1)%n];

	while (m--) {
		string op; cin >> op;
		if (op == "BN") {
			cin >> i >> j; cout << node[i].nxt << '\n';
			node[j] = {i, node[i].nxt};
			node[node[i].nxt].prv = j, node[i].nxt = j;
		}
		else if (op == "BP") {
			cin >> i >> j; cout << node[i].prv << '\n';
			node[j] = {node[i].prv, i};
			node[node[i].prv].nxt = j, node[i].prv = j;
		}
		else if (op == "CN") {
			cin >> i; 
			int closeIdx = node[i].nxt; cout << closeIdx << '\n';
			node[node[closeIdx].nxt].prv = i;
			node[i].nxt = node[closeIdx].nxt;
		}
		else {
			cin >> i;
			int closeIdx = node[i].prv; cout << closeIdx << '\n';
			node[node[closeIdx].prv].nxt = i;
			node[i].prv = node[closeIdx].prv;
		}
	}
}