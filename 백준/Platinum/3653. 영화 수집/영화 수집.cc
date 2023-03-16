#include <bits/stdc++.h>
using namespace std;

const int MX = 100001;
int n, m, node[MX], fenwick[2*MX];

void update(int idx, int val) {
	while (idx <= n + m) {
		fenwick[idx] += val;
		idx += idx & -idx;
	}
}
/* [1, idx]까지의 부분합 */
int query(int idx) {
	int ans = 0;
	while (idx > 0) {
		ans += fenwick[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			node[i] = n + 1 - i;
			update(i, 1);
		}
		for (int x = 1; x <= m; x++) {
			int a; cin >> a;
			cout << n - query(node[a]) << ' ';
			update(node[a], -1);
			node[a] = n + x;
			update(node[a], 1);
		}
		cout << '\n';
        memset(fenwick, 0, sizeof(fenwick));
	}
}