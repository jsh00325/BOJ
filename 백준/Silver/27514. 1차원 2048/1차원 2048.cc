#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll x, sum = 0; for (int i = 0; i < n; ++i) cin >> x, sum += x;
	for (int i = 62; i >= 0; --i) if (sum & ((ll)1 << i)) {
		cout << ((ll)1 << i); break;
	}
}