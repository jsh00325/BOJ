#include <bits/stdc++.h>
using namespace std;

int from[1000000];
bool visit[1000000];

void bfs(int n) {
	memset(visit, false, sizeof(bool) * 1000000);
	queue<int> q;
	q.push(1 % n); visit[1 % n] = true; from[1 % n] = 1;
	while (!q.empty()) {
		int cur_mod = q.front(); q.pop();
		if (!cur_mod) break;

		int nxt_mod = (cur_mod * (10 % n)) % n;
		if (!visit[nxt_mod]) {
			q.push(nxt_mod); visit[nxt_mod] = true; from[nxt_mod] = cur_mod;
		}

		nxt_mod = (nxt_mod + (1 % n)) % n;
		if (!visit[nxt_mod]) {
			q.push(nxt_mod); visit[nxt_mod] = true; from[nxt_mod] = cur_mod;
		}
	}
}
void print_ans(int n) {
	string rslt;
	int cur = 0;
	while (cur != 1) {
		if ((from[cur] * (10 % n)) % n == cur) rslt += "0";
		else rslt += "1";
		cur = from[cur];
	} rslt += "1";
	reverse(rslt.begin(), rslt.end());
	cout << rslt << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n;  cin >> n;
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		bfs(n);
		print_ans(n);
	}
}