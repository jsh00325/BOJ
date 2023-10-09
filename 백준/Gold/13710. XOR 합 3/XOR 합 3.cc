#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

ll arr[100000], rslt;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	FOR(i, n) cin >> arr[i];

	FOR(i, 30) {
		vector<int> v(n);
		FOR(j, n) v[j] = (arr[j] >> i) & 1;

		ll ans = v[0], prev = v[0];
		FOR1(j, n-1)
			if (v[j]) prev = (j - prev) + v[j], ans += prev;
			else ans += prev;
		rslt += ans * (1 << i); 
	}
	cout << rslt;
}