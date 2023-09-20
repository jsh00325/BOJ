#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1e6;
int n, q;
ll fw[MX+1];

void update(int idx, int val) {
	while (idx <= n) {
		fw[idx] += val;
		idx += (idx & (-idx));
	}
}
ll query(int idx) {
	ll ans = 0;
	while (idx >= 1) {
		ans += fw[idx];
		idx -= (idx & (-idx));
	} return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(c) - query(b-1) << '\n';
	}	
}