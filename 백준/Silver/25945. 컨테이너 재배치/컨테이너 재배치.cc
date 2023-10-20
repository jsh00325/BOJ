#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll n, m = 0, ans = 0; cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) { cin >> v[i]; m += v[i]; }
	sort(v.begin(), v.end());
	ll base = m / n, small = n - (m % n);
	for (int i = 0; i < n; ++i) {
		if (i < small) ans += abs(base - v[i]);
		else ans += abs(v[i] - (base + 1));
	} cout << ans / 2;
}