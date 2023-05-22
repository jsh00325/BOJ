#include <bits/stdc++.h>
using namespace std;
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)
typedef struct { int x, y; } Node;

const int MX = 1e5 + 3, INF = -0x77777777;
int n, m, a, b, c, arr[MX];
Node seg[4 * MX];

Node merge(const Node& a, const Node& b) {
	if (a.x > b.x) return { a.x, max(a.y, b.x) };
	else return { b.x, max(a.x, b.y) };
}
void build(int node, int st, int en) {
	if (st == en) { seg[node] = { arr[st], INF }; return; }
	int mid = (st + en) / 2;
	build(node * 2, st, mid);
	build(node * 2 + 1, mid + 1, en);
	seg[node] = merge(seg[node*2], seg[node*2 + 1]);
}
void update(int node, int st, int en, int idx, int val) {
	if (idx < st || en < idx) return;
	if (st == en) { seg[node] = { val, INF }; return; }
	int mid = (st + en) / 2;
	update(node * 2, st, mid, idx, val);
	update(node * 2 + 1, mid + 1, en, idx, val);
	seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
}
Node query(int node, int st, int en, int l, int r) {
	if (en < l || r < st) return { INF, INF };
	if (l <= st && en <= r) return seg[node];
	int mid = (st + en) / 2;
	Node leftVal = query(node * 2, st, mid, l, r);
	Node rightVal = query(node * 2 + 1, mid + 1, en, l, r);
	return merge(leftVal, rightVal);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n; FOR1(i, n) cin >> arr[i];
	build(1, 1, n);
	cin >> m; FOR1(i, m) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else {
			Node rslt = query(1, 1, n, b, c);
			cout << rslt.x + rslt.y << '\n';
		}
	}
}