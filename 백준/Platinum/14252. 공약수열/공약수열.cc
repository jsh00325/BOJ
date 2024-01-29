#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> v(n); for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 1; i < n; ++i) {
		if (__gcd(v[i-1], v[i]) == 1) continue;
		
		int res = -1;
		for (int x = v[i-1]+1; x < v[i]; ++x) {
			if (__gcd(v[i-1], x) == 1 && __gcd(x, v[i]) == 1) {
				res = x; break;
			}
		}
		ans += (res == -1 ? 2 : 1);
	} cout << ans;
}