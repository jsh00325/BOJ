#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1e6 + 3, MOD = 1e9 + 7;
int n, m, k, arr[MX], segTree[4 * MX];

int merge(int a, int b) { return ((ll)a * (ll)b) % MOD; }
int build(int node, int l, int r) {
	if (l == r) return segTree[node] = arr[l];

	int mid = (l + r) / 2;
	int lval = build(node * 2, l, mid);
	int rval = build(node * 2 + 1, mid + 1, r);
	return segTree[node] = merge(lval, rval);
}
int update(int idx, int val, int node, int l, int r) {
	if (idx < l || r < idx) return segTree[node];
	if (l == r) return segTree[node] = val;

	int mid = (l + r) / 2;
	int lval = update(idx, val, node * 2, l, mid);
	int rval = update(idx, val, node * 2 + 1, mid + 1, r);
	return segTree[node] = merge(lval, rval);
}
int query(int s, int e, int node, int l, int r) {
	if (r < s || e < l) return 1;
	if (s <= l && r <= e) return segTree[node];

	int mid = (l + r) / 2;
	int lval = query(s, e, node * 2, l, mid);
	int rval = query(s, e, node * 2 + 1, mid + 1, r);
	return merge(lval, rval);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) update(b, c, 1, 1, n);
		else cout << query(b, c, 1, 1, n) << '\n';
	}
}