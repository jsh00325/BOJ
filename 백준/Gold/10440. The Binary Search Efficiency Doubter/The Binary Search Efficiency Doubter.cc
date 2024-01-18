#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll table[10000000];
ll dp(int len) {
	if (len <= 4) return (ll)("01358"[len] - '0');
	if (table[len] != -1) return table[len];

	table[len] = len;
	return table[len] += dp((len-1) >> 1) + dp(len >> 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(table, -1, sizeof(table));

	int x, cnt = 0;
	while (cin >> x) cout << "Case " << ++cnt << ": " << dp(x) << '\n';	
}