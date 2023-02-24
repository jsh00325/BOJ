#include <bits/stdc++.h>
using namespace std;

const int TREE_MX = 1e6 + 3, MX = 1e6;
int arr[TREE_MX], segTree[4 * TREE_MX];

int update(int idx, int val, int node, int l, int r) {
	if (idx < l || r < idx) return segTree[node];
	if (l == r) return segTree[node] += val;

	int mid = (l + r) / 2;
	return segTree[node] = update(idx, val, node * 2, l, mid) + update(idx, val, node * 2 + 1, mid + 1, r);
}

int query(int x, int node, int l, int r) {
	if (l == r) return l;

	int mid = (l + r) / 2;
	if (x <= segTree[node * 2]) return query(x, node * 2, l, mid);
	else return query(x - segTree[node * 2], node * 2 + 1, mid + 1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	while (n--) {
		int a; cin >> a;
		if (a == 1) {
			int b; cin >> b;
			int q = query(b, 1, 0, MX);
			cout << q << '\n';
			update(q, -1, 1, 0, MX);
		}
		else {
			int b, c; cin >> b >> c;
			update(b, c, 1, 0, MX);
		}
	}
}