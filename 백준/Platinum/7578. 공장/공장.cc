#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX1 = 500001, MX2 = 1000001;
int n, numbering[MX2], order[MX1], BIT[MX1];

void update(int x) {
	while (x <= n) {
		BIT[x]++;
		x = x + (x & -x);
	}
}
int sum(int x) {
	if (x == 0) return 0;
	else return BIT[x] + sum(x - (x & -x));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		numbering[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		order[numbering[x]] = i;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		update(order[i]);
		ans += sum(n) - sum(order[i]);
	}
	cout << ans;
}