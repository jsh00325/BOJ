#include <bits/stdc++.h>
using namespace std;

int stat[200001][4], prv_dp[1<<4][12], cur_dp[1<<4][12];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) for (int st = 0; st < 4; ++st) cin >> stat[i][st];

	for (int st = 0; st < 4; ++st) prv_dp[1<<st][1] = cur_dp[1<<st][1] = stat[1][st];

	for (int i = 2; i <= n; ++i) {
		for (int prv_st = 0; prv_st < 16; ++prv_st) for (int cur_st = 0; cur_st < 3; ++cur_st) {
			int nxt_st = prv_st | (1 << cur_st);
			for (int nm = 1; nm <= min(11, i); ++nm) 
				cur_dp[nxt_st][nm] = max(cur_dp[nxt_st][nm], prv_dp[prv_st][nm-1] + stat[i][cur_st]);
		}
		for (int prv_st = 0; prv_st < 8; ++prv_st) for (int nm = 1; nm <= min(11, i); ++nm) 
			cur_dp[prv_st + 8][nm] = max(cur_dp[prv_st + 8][nm], prv_dp[prv_st][nm-1] + stat[i][3]);
		
		for (int st = 0; st < 16; ++st) for (int i = 0; i <= 11; ++i) prv_dp[st][i] = cur_dp[st][i];
	} cout << prv_dp[0b1111][11];
}