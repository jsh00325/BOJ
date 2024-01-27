#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		ll n, m; cin >> n >> m; if (n>m) swap(n, m);
		cout << (2*n >= m ? n : n+1) << ' ';
		if (n == m) cout << 3 << '\n';
		else if (m <= 2*(n+1)) cout << (n==1 & m==3 ? 5 : 7) << '\n';
		else cout << 7 + 2*(m-2*(n+1)) << '\n';
	}
}