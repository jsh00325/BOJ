#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 1, MIN_NONE = 1e9 - 1, MAX_NONE = 0;
int n, m, arr[MX], minTree[4*MX], maxTree[4*MX];

int min_merge(int a, int b) { return a < b ? a : b; }
int max_merge(int a, int b) { return a > b ? a : b; }

int build(int segTree[], int node, int l, int r, int (*merge)(int, int)) {
	if (l == r) return segTree[node] = arr[l];

	int mid = (l + r) / 2;
	int lval = build(segTree, node * 2, l, mid, merge);
	int rval = build(segTree, node * 2 + 1, mid + 1, r, merge);
	return segTree[node] = merge(lval, rval);
}
int query(int segTree[], int s, int e, int node, int l, int r, int (*merge)(int, int), int none) {
	if (r < s || e < l) return none;
	if (s <= l && r <= e) return segTree[node];

	int mid = (l + r) / 2;
	int lval = query(segTree, s, e, node * 2, l, mid, merge, none);
	int rval = query(segTree, s, e, node * 2 + 1, mid + 1, r, merge, none);
	return merge(lval, rval);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	build(minTree, 1, 0, n - 1, min_merge);
	build(maxTree, 1, 0, n - 1, max_merge);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << query(minTree, a - 1, b - 1, 1, 0, n - 1, min_merge, MIN_NONE) << ' ';
		cout << query(maxTree, a - 1, b - 1, 1, 0, n - 1, max_merge, MAX_NONE) << '\n';
	}
}