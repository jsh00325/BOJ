#include <iostream>
using namespace std;

typedef long long ll;
#define MX 1000000000

int n;
ll dp[101][10][1<<10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= 9; i++) dp[1][i][1<<i] = 1;
	
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k < (1<<10); k++)
				if (j == 0) dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][1][k]) % MX;
				else if (j == 9) dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][8][k]) % MX;
				else dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j-1][k] + dp[i-1][j+1][k]) % MX;

	ll rslt = 0;
	for (int i = 0; i < 10; i++)
		rslt = (rslt + dp[n][i][(1<<10)-1]) % MX;
	cout << rslt;
}