#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)

const int MX = 1e5 + 3;
int n, m, q, l, r, arr[MX];
ll k, bit[MX];

void update(int idx, ll val) {
	while (idx <= n) {
		bit[idx] += val;
		idx += (idx & -idx);
	}
}
ll query(int idx) {
	ll ans = 0;
	while (idx > 0) {
		ans += bit[idx];
		idx -= (idx & -idx);
	} return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n; FOR1(i, n) cin >> arr[i];
	cin >> m; FOR1(i, m) {
		cin >> q;
		if (q == 1) {
			cin >> l >> r >> k;
			update(l, k); update(r + 1, -k);
		}
		else {
			cin >> k;
			cout << arr[k] + query(k) << '\n';
		}
	}
}