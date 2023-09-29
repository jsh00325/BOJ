#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		vector<ll> a(n+1), pos;
		FOR1(i, n) {
			cin >> a[i];
			if (a[i] >= 0) pos.push_back(i);
		}

		ll oddSum = 0, sum = 0;
		for (auto x : pos) sum += a[x];
		if (pos.empty() || pos[0] >= 4 || pos[0] & 1) { cout << sum << '\n'; continue; }

		FOR(i, pos.size()) if (pos[i] & 1) {
			for (int j = i; j < pos.size(); ++j) oddSum += a[pos[j]];
			pos.resize(i); break;
		}
		cout << max(a[1] + sum, sum - a[pos[0]]) << '\n';
	}
}