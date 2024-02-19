#include <bits/stdc++.h>
using namespace std;

int n, table[2000][2000], v[2000];
int dp(int i, int j) {
	if (i == j) return table[i][j] = v[i] * n;
	int& ret = table[i][j];
	if (ret != -1) return ret;
	int lval = v[i] * (n-j+i) + dp(i+1, j);
	int rval = dp(i, j-1) + v[j] * (n-j+i);
	return ret = max(lval, rval);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> v[i];
	memset(table, -1, sizeof(table));
	cout << dp(0, n-1);	
}