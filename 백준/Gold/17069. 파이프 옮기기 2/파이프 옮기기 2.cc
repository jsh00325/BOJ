#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, arr[35][35];
ll table[35][35][3];

ll dp(int i, int j, int k) {
	ll& ret = table[i][j][k];
	if (ret != -1) return ret;
	
	if (k == 0) {
		if (j == 0 || arr[i][j]) return ret = 0;
		return ret = dp(i, j-1, 0) + dp(i, j-1, 2);
	}
	else if (k == 1) {
		if (i == 0 || arr[i][j]) return ret = 0;
		return ret = dp(i-1, j, 1) + dp(i-1, j, 2);
	}
	else {
		if (i == 0 || j == 0 || arr[i][j] || arr[i-1][j] || arr[i][j-1]) return ret = 0;
		return ret = dp(i-1, j-1, 0) + dp(i-1, j-1, 1) + dp(i-1, j-1, 2);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	memset(table, -1, sizeof(table));
	table[0][1][0] = 1;

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];
	cout << dp(n-1, n-1, 0) + dp(n-1, n-1, 1) + dp(n-1, n-1, 2);
}