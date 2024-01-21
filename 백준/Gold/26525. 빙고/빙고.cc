#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll ans, fact[10001];
string arr[100];

ll mpow(ll a, ll b = MOD-2) {
	ll ans = 1;
	while (b > 0) {
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD, b >>= 1;
	} return ans;
}
ll mdiv(ll a, ll b) { return a * mpow(b) % MOD; }
ll comb(ll n, ll k) { return mdiv(fact[n], fact[k]*fact[n-k]%MOD); }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 10000; ++i) fact[i] = (fact[i-1] * i) % MOD;

	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int empty = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (arr[i][j] == '0') ++empty;

	ll btm = comb(empty, k);

	for (int r = 0; r < n; ++r) {
		int cur_empty = 0;
		for (int c = 0; c < n; ++c) if (arr[r][c] == '0') ++cur_empty;
		if (cur_empty > k) continue;
		ans = (ans + mdiv(comb(empty - cur_empty, k - cur_empty), btm)) % MOD;
	}
	for (int c = 0; c < n; ++c) {
		int cur_empty = 0;
		for (int r = 0; r < n; ++r) if (arr[r][c] == '0') ++cur_empty;
		if (cur_empty > k) continue;
		ans = (ans + mdiv(comb(empty - cur_empty, k - cur_empty), btm)) % MOD;
	}
	int dia1 = 0, dia2 = 0;
	for (int i = 0; i < n; ++i) if (arr[i][i] == '0') ++dia1;
	for (int i = 0; i < n; ++i) if (arr[i][n-i-1] == '0') ++dia2;
	if (dia1 <= k) ans = (ans + mdiv(comb(empty - dia1, k - dia1), btm)) % MOD;
	if (dia2 <= k) ans = (ans + mdiv(comb(empty - dia2, k - dia2), btm)) % MOD;
	
	cout << fact[n*n] * ans % MOD;
}