#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		ll n, k; cin >> n >> k;
		while (k > 0 && n > 0) n >>= 1, --k;
		cout << ((n + 1) >> 1) << '\n';
	}
}