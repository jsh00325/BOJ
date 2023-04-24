#include <bits/stdc++.h>
using namespace std;

const int MX = 300000, MOD = 1e9 + 7;
long long n, ans, arr[MX], two_mod[MX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	two_mod[0] = 1;
	for (int i = 1; i < n; i++)
		two_mod[i] = (two_mod[i - 1] * 2) % MOD;

	for (int i = 0; i < n; i++)
		ans = (ans + (arr[i] % MOD * (two_mod[i] - two_mod[n - 1 - i] + MOD) % MOD) % MOD) % MOD;
	cout << ans;
}