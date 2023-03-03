#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];

		stack<int> s;
		ll ans = 0;
		for (int i = n-1; i >= 0; i--) {
			if (s.empty()) s.push(v[i]);
			else if (s.top() < v[i]) s.push(v[i]);
			else ans += (ll)s.top() - v[i];
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}