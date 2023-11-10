#include <bits/stdc++.h>
using namespace std;
struct node { int leftMax, rightMax, curMax, prefixSum; };

const int MX = 1e5 + 3, NEGINF = -987654321;
int n, arr[MX];
node tree[4 * MX];

node calc(const node& a, const node& b) {
	return node {
		max(a.leftMax, a.prefixSum + b.leftMax),
		max(b.rightMax, a.rightMax + b.prefixSum),
		max(max(a.curMax, b.curMax), a.rightMax + b.leftMax),
		a.prefixSum + b.prefixSum
	};
}

void build(int st, int en, int idx) {
	if (st == en) { tree[idx] = {arr[st], arr[st], arr[st], arr[st]}; return; }

	int mid = (st + en) / 2, lidx = idx << 1, ridx = lidx + 1;
	build(st, mid, lidx), build(mid+1, en, ridx);
	tree[idx] = calc(tree[lidx], tree[ridx]);
}

node query(int st, int en, int idx, int l, int r) {
	if (en < l || r < st) return tree[0];
	if (l <= st && en <= r) return tree[idx];

	int mid = (st + en) / 2; 
	node lq = query(st, mid, idx << 1, l, r), rq = query(mid + 1, en, (idx << 1) + 1, l, r);
	return calc(lq, rq);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n; for (int i = 1; i <= n; ++i) cin >> arr[i];

	tree[0] = {NEGINF, NEGINF, NEGINF, 0}, build(1, n, 1);
	int q; cin >> q;
	while (q--) {
		int i, j; cin >> i >> j;
		node ans = query(1, n, 1, i, j);
		cout << ans.curMax << '\n';
	}
}