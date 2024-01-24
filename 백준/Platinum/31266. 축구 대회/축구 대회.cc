#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
struct node { int x, y; };

ll dp[200000][1<<4], stat[200000][4];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; ++i) for (int st = 0; st < 4; ++st) cin >> stat[i][st];

	for (int st = 0; st < 4; ++st) dp[0][1<<st] = stat[0][st];
	for (int i = 1; i < n; ++i) for (int pr_st = 0; pr_st < (1<<4); ++pr_st) for (int cur = 0; cur < 4; ++cur)
		if (cur != 3 || !(pr_st & 8)) dp[i][pr_st | (1 << cur)] = max(dp[i][pr_st | (1 << cur)], dp[i-1][pr_st] + stat[i][cur]);
	cout << dp[n-1][0b1111];
}