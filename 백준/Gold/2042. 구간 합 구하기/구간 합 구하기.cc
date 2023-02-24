#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1e6 + 3;
int n, m, k;
ll arr[MX], segTree[4 * MX];

ll build(int node, int l, int r) {
	if (l == r) return segTree[node] = arr[l];

	int mid = (l + r) / 2;
	ll lval = build(node * 2, l, mid);
	ll rval = build(node * 2 + 1, mid + 1, r);
	return segTree[node] = lval + rval;
}

ll update(int idx, ll val, int node, int l, int r) {
	if (idx < l || r < idx) return segTree[node];
	if (l == r) return segTree[node] = val;

	int mid = (l + r) / 2;
	ll lval = update(idx, val, node * 2, l, mid);
	ll rval = update(idx, val, node * 2 + 1, mid + 1, r);
	return segTree[node] = lval + rval;
}
ll sum(int s, int e, int node, int l, int r) {
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return segTree[node];

	int mid = (l + r) / 2;
	ll lval = sum(s, e, node * 2, l, mid);
	ll rval = sum(s, e, node * 2 + 1, mid + 1, r);
	return lval + rval;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	build(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		ll a, b, c; cin >> a >> b >> c;
		if (a == 1) update(b - 1, c, 1, 0, n - 1);
		else cout << sum(b - 1, c - 1, 1, 0, n - 1) << '\n';
	}
}