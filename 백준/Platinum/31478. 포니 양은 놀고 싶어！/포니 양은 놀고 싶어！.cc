#include <bits/stdc++.h>
using namespace std;

int a, k, l, b, c;

int mpow(int a, int b, int mod) {
	a %= mod;
	int rslt = 1;
	while (b > 0) {
		if (b & 1) rslt = (rslt * a) % mod;
		a = (a * a) % mod; b >>= 1;
	} return rslt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b >> c >> k >> l;

	int df = mpow(a, mpow(b, c, 6), 7);
	int ds = (mpow(b, c, 7) * ((a*a*a*a*a) % 7)) % 7;

	int ans = ((k + df) % 7 == l) + 2 * ((k + ds) % 7 == l);
	cout << ans;
}