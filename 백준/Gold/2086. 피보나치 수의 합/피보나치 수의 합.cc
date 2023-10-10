#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

const ll MOD = 1e9;
struct mat33 {
	ll arr[3][3];

	mat33() { memset(arr, 0, sizeof(arr)); }

	void set_diagonal() { arr[0][0] = arr[1][1] = arr[2][2] = 1; }
	void set_base() { arr[0][0] = arr[0][1] = arr[0][2] = arr[1][0] = arr[2][2] = 1; }
	mat33& operator*= (const mat33& other) {
		mat33 rslt;
		FOR(i, 3) FOR(j, 3) FOR(k, 3)
			rslt.arr[i][j] = (rslt.arr[i][j] + (arr[i][k] * other.arr[k][j]) % MOD) % MOD;
		FOR(i, 3) FOR(j, 3) arr[i][j] = rslt.arr[i][j];
		return *this;
	}
};

ll sum(ll x) {
	if (x < 3) return x;
	mat33 base, rslt;
	base.set_base(), rslt.set_diagonal();
	--x;
	while (x > 0) {
		if (x & 1) rslt *= base;
		base *= base;
		x >>= 1;
	}
	return (2 * rslt.arr[1][0] + rslt.arr[1][1] + rslt.arr[1][2]) % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b; cin >> a >> b;
	cout << (sum(b) - sum(a-1) + MOD) % MOD;	
}