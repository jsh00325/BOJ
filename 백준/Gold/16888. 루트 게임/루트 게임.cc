#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6;
bool dp[MX+1];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 1; i <= MX; ++i)
		for (int j = 1; i - j*j >= 0; ++j)
			if (!dp[i-j*j]) { dp[i] = true; break; }

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		cout << (dp[n] ? "koosaga" : "cubelover") << '\n';
	}
}