#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll g(ll x) {
	if (x == 0) return 0;
	ll rslt = 0;
	for (int ps = 0; ; ++ps) {
		ll cur = (x >> ps) - (x >> (ps + 1));
		if (cur == 0) break;
		rslt += cur * ((ll)1 << ps);
	} return rslt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b; cin >> a >> b;
	cout << g(b) - g(a-1);
}