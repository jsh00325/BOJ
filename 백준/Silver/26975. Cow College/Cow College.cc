#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<ll> v(n); for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	ll mx = 0, ans = 0;
	for (int i = 0; i < n; ++i) if (mx < (n-i)*v[i]) mx = (n-i)*v[i], ans = v[i];
	cout << mx << ' ' << ans;
}