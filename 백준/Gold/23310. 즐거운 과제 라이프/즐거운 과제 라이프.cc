#include <bits/stdc++.h>
using namespace std;
int x[20001], tmp[20001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> x[i];

	int lcm = n * m / __gcd(n, m);
	for (int d = 1; d <= lcm; ++d) {
		if (d % m != 0) ++tmp[(d-1)%n+1];
	}

	int lday = 0x7fffffff;
	for (int i = 1; i <= n; ++i) if (tmp[i]) lday = min(lday, (int)ceil((double)x[i] / tmp[i]));
	for (int i = 1; i <= n; ++i) x[i] -= tmp[i] * (lday-1);

	for (int d = 1; d <= lcm; ++d) {
		if (d % m != 0 && --x[(d-1)%n+1] == 0) {
			cout << (d-1) % n + 1; break;
		}
	}
}