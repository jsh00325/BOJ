#include <bits/stdc++.h>
using namespace std;
struct node { int x, y; };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		
		int b2 = 0;
		vector<node> ans;
		if (n == 1) ans.push_back({0, 0});

		while (n > 1) {
			while (n % 2 == 0) n /= 2, ++b2;

			int b3 = 0, temp = 1;
			while (temp * 3 <= n) ++b3, temp *= 3;
			ans.push_back({b2, b3});

			n -= temp;
		}
		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x.x << ' ' << x.y << '\n';
	}
}