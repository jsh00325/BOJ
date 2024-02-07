#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll table[32][32];
ll dp(int i, int j) {
	if (table[i][j] != -1) return table[i][j];
	if (i == 0 || j == 0) return table[i][j] = 1;
	return table[i][j] = dp(i-1, j) + dp(i-1, j-1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll N, L, I; cin >> N >> L >> I;
	memset(table, -1, sizeof(table));

	for (int i = N; i >= 1; --i) {
		if (dp(i-1, L) < I) { cout << 1; I -= dp(i-1, L); --L;}
		else cout << 0;
	}
}