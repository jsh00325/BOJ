#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1e5+3, INF = 0x7fffffff, INF_IDX = 1e5+2;
int n, arr[MX], min_st[4 * MX], idx_st[4 * MX];

int build_min(int node, int l, int r) {
	if (l == r) return min_st[node] = arr[l];

	int mid = (l + r) / 2;
	return min_st[node] = min(build_min(node * 2, l, mid), build_min(node * 2 + 1, mid + 1, r));
}
int merge(int a, int b) {
	if (arr[a] == arr[b]) return min(a, b);
	else return (arr[a] < arr[b] ? a : b);
}
int build_idx(int node, int l, int r) {
	if (l == r) return idx_st[node] = l;

	int mid = (l + r) / 2;
	return idx_st[node] = merge(build_idx(node * 2, l, mid), build_idx(node * 2 + 1, mid + 1, r));
}
int query_min(int s, int e, int node, int l, int r) {
	if (e < l || r < s) return INF;
	if (s <= l && r <= e) return min_st[node];

	int mid = (l + r) / 2;
	int lval = query_min(s, e, node * 2, l, mid);
	int rval = query_min(s, e, node * 2 + 1, mid + 1, r);
	return min(lval, rval);
}
int query_idx(int s, int e, int node, int l, int r) {
	if (e < l || r < s) return INF_IDX;
	if (s <= l && r <= e) return idx_st[node];

	int mid = (l + r) / 2;
	int lval = query_idx(s, e, node * 2, l, mid);
	int rval = query_idx(s, e, node * 2 + 1, mid + 1, r);
	return merge(lval, rval);
}
ll solve(int st, int en) {
	if (st == en) return arr[st];

	ll min_value = query_min(st, en, 1, 0, n - 1);
	int min_idx = query_idx(st, en, 1, 0, n - 1);

	ll area = min_value * (ll)(en - st + 1);
	if (st < min_idx) area = max(area, solve(st, min_idx - 1));
	if (min_idx < en) area = max(area, solve(min_idx + 1, en));
	return area;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[INF_IDX] = INF;
	while (true) {
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++) cin >> arr[i];
		build_min(1, 0, n - 1); build_idx(1, 0, n - 1);
		cout << solve(0, n - 1) << '\n';
	}
}