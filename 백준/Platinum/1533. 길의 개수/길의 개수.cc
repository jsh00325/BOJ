#include <iostream>
#include <cstring>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)
typedef long long ll;

const int MOD = 1e6 + 3;
struct MAT {
	ll arr[50][50];

	MAT() { memset(arr, 0, sizeof(arr)); }
	MAT(int val) {
		memset(arr, 0, sizeof(arr));
		FOR(i, 50) arr[i][i] = val;
	}
	MAT operator*(const MAT& a) {
		MAT rslt;
		FOR(i, 50) FOR(j, 50) FOR(k, 50)
			rslt.arr[i][j] = (rslt.arr[i][j] + (arr[i][k] * a.arr[k][j]) % MOD) % MOD;
		return rslt;
	}
};

MAT rslt(1), adj;
int n, s, e, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s >> e >> t;
	FOR(i, n) FOR1(j, 4) {
		int idx = 5 * i + j;
		adj.arr[idx][idx - 1] = 1;
	}
	FOR(i, n) {
		string str; cin >> str;
		FOR(j, n) {
			int w = str[j] - '0';
			if (w == 0) continue;
			if (w == 1) adj.arr[5 * i][5 * j]++;
			else adj.arr[5 * i][5 * j + w - 1]++;
		}
	}

	while (t > 0) {
		if (t & 1) rslt = rslt * adj;
		adj = adj * adj;
		t >>= 1;
	}
	cout << rslt.arr[5 * (s - 1)][5 * (e - 1)];
}