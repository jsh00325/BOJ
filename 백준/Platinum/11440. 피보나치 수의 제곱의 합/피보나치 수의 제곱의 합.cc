#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

const ll MOD = 1e9+7;

struct MAT {
	ll arr[2][2];

	MAT() { MEM(arr, 0); }
	MAT operator* (const MAT& other) {
		MAT rslt;
		FOR(i, 2) FOR(j, 2) FOR(k, 2) {
			rslt.arr[i][j] += (arr[i][k] * other.arr[k][j]) % MOD;
			rslt.arr[i][j] %= MOD;
		} return rslt;
	}
} rslt, base;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n; cin >> n;

	rslt.arr[0][0] = rslt.arr[1][1] = 1;
	base.arr[0][0] = base.arr[0][1] = base.arr[1][0] = 1;

	while (n > 0) {
		if (n & 1) rslt = rslt * base;
		base = base * base, n >>= 1;
	}
	cout << (rslt.arr[0][0] * rslt.arr[1][0]) % MOD;
}