#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

const int MOD = 1000;
int n;

struct MAT {
	int arr[5][5];

	MAT() { memset(arr, 0, sizeof(arr)); }
	MAT(const MAT& a) { FOR(i, n) FOR(j, n) arr[i][j] = a.arr[i][j]; }

	void setUnit() { FOR(i, n) arr[i][i] = 1; }
	MAT operator* (const MAT& other) {
		MAT ans;
		FOR(i, n) FOR(j, n) {
			FOR(k, n) ans.arr[i][j] += (arr[i][k] * other.arr[k][j]) % MOD;
			ans.arr[i][j] %= MOD;
		} return ans;
	}
	MAT operator+ (const MAT& other) {
		MAT ans;
		FOR(i, n) FOR(j, n) ans.arr[i][j] = (arr[i][j] + other.arr[i][j]) % MOD;
		return ans;
	}
	
	void print_mat() {
		FOR(i, n) { FOR(j, n) cout << arr[i][j] << ' '; cout << '\n'; }
	}
} a;

MAT mpow(const MAT& a, ll x) {
	MAT ans, base(a); ans.setUnit();
	while (x > 0) {
		if (x & 1) ans = ans * base;
		base = base * base;
		x >>= 1;
	} return ans;
}

MAT solve(ll x) {
	if (x == 1) return a;
	MAT rslt = solve(x >> 1);
	if (x & 1) {
		MAT temp; temp.setUnit();
		return rslt + (mpow(a, (x >> 1) + 1) * (temp + rslt));
	}
	else return rslt + (mpow(a, x >> 1) * rslt);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll b;
	cin >> n >> b;
	FOR(i, n) FOR(j, n) cin >> a.arr[i][j], a.arr[i][j] %= MOD;
	solve(b).print_mat();
}