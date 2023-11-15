#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

const ll MOD = 1234567891;
ll n, l;

struct MAT {
	ll arr[4][4];

	MAT() { MEM(arr, 0); }
	void setI() { FOR(i, 4) arr[i][i] = 1; }

	MAT operator* (const MAT& other) {
		MAT ans;
		FOR(i, 4) FOR(j, 4) FOR(k, 4)
			ans.arr[i][j] = (ans.arr[i][j] + (arr[i][k] * other.arr[k][j]) % MOD) % MOD;
		return ans;
	}
} base, rslt;

unordered_set<int> us[2][2];
int check_gold(int x) {
	while (x >= 10) {
		if (x % 10 != 4 && x % 10 != 7) return -1;
		x /= 10;
	} return (x == 4 || x == 7 ? x : -1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> l;
	FOR(i, n) {
		int x; cin >> x;
		int st = check_gold(x), en = x % 10;
		if (st == -1 || (en != 4 && en != 7)) continue;
		st = (st == 7), en = (en == 7);
		if (us[st][en].find(x) == us[st][en].end()) us[st][en].insert(x);
	}

	FOR(i, 2) FOR(j, 2) base.arr[i][j] = us[j][i].size();
	base.arr[2][0] = base.arr[3][1] = 1;
	rslt.setI();

	--l;
	while (l > 0) {
		if (l & 1) rslt = rslt * base;
		base = base * base, l >>= 1;
	}

	ll ans1 = 0, ans2 = 0, vb[4] = {(ll)us[0][0].size() + (ll)us[1][0].size(), (ll)us[0][1].size() + (ll)us[1][1].size(), 1, 1};
	FOR(k, 4) ans1 = (ans1 + (rslt.arr[0][k] * vb[k]) % MOD) % MOD;
	FOR(k, 4) ans2 = (ans2 + (rslt.arr[1][k] * vb[k]) % MOD) % MOD;
	cout << (ans1 + ans2) % MOD;
}