#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

struct COIN { int value, cnt; };
COIN coins[100];
bool dp[50001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	FOR(tc, 3) {
		int n, sum = 0; cin >> n;
		FOR(i, n) cin >> coins[i].value >> coins[i].cnt, sum += coins[i].value * coins[i].cnt;
		if (sum & 1) { cout << "0\n"; continue; }
		MEM(dp, false); dp[0] = true; sum >>= 1;
		FOR(cIdx, n) {
			COIN& curCoin = coins[cIdx];
			for (int curIdx = sum; curIdx >= 0; --curIdx) if (dp[curIdx]) {
				int nxtIdx = curIdx;
				FOR(i, curCoin.cnt) {
					nxtIdx += curCoin.value;
					if (nxtIdx > sum || dp[nxtIdx]) break;
					dp[nxtIdx] = true;
				}
			}
			if (dp[sum]) break;
		}
		cout << dp[sum] << '\n';
	}
}