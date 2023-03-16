#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int n, k, c[49][49], ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i <= 48; i++) c[i][0] = 1;
	for (int i = 1; i <= 48; i++)
		for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	
	cin >> n;
	k = n / 4;
	for (int i = 1; i <= k; i += 2)
		ans = (ans + (c[13][i] * c[52 - 4 * i][n - 4 * i]) % MOD) % MOD;
	for (int i = 2; i <= k; i += 2)
		ans = (ans + MOD - (c[13][i] * c[52 - 4 * i][n - 4 * i]) % MOD) % MOD;
	cout << ans;
}