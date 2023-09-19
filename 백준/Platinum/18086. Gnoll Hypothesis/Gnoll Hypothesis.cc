#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
double arr[500], rat[500];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10);

	int n, k; cin >> n >> k;
	FOR(i, n) cin >> arr[i];

	rat[0] = (double)k / n;
	for (int i = 1; i < n; i++) rat[i] = rat[i-1] * (n - k - i + 1) / (n - i);

	FOR(i, n) {
		double ans = 0;
		for (int a = 0; a <= n - k; a++) ans += rat[a] * arr[(i - a + n) % n];
		cout << ans << ' ';
	}
}