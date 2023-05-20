#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)

const int MX = 1e6 + 3;
int n, m, k, a, b, c;
ll d, arr[MX], seg[4 * MX], lazy[4 * MX];

ll build(int node, int st, int en) {
	if (st == en) return seg[node] = arr[st];
	int mid = (st + en) / 2;
	ll leftVal = build(node * 2, st, mid);
	ll rightVal = build(node * 2 + 1, mid + 1, en);
	return seg[node] = leftVal + rightVal;
}
void lazyUpdate(int node, int st, int en) {
	if (lazy[node]) {
		seg[node] += (ll)(en - st + 1) * lazy[node];
		if (st != en) (lazy[node * 2] += lazy[node]), (lazy[node * 2 + 1] += lazy[node]);
		lazy[node] = 0;
	}
}
ll update(int node, int st, int en, int l, int r, ll val) {
	lazyUpdate(node, st, en);
	if (en < l || r < st) return seg[node];
	if (l <= st && en <= r) {
		lazy[node] += val;
		lazyUpdate(node, st, en);
		return seg[node];
	}
	int mid = (st + en) / 2;
	ll leftVal = update(node * 2, st, mid, l, r, val);
	ll rightVal = update(node * 2 + 1, mid + 1, en, l, r, val);
	return seg[node] = leftVal + rightVal;
}
ll query(int node, int st, int en, int l, int r) {
	lazyUpdate(node, st, en);
	if (en < l || r < st) return 0;
	if (l <= st && en <= r) return seg[node];
	int mid = (st + en) / 2;
	ll leftVal = query(node * 2, st, mid, l, r);
	ll rightVal = query(node * 2 + 1, mid + 1, en, l, r);
	return leftVal + rightVal;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	FOR1(i, n) cin >> arr[i];
	build(1, 1, n);
	FOR(i, m + k) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d; update(1, 1, n, b, c, d);
		}
		else cout << query(1, 1, n, b, c) << '\n';
	}
}