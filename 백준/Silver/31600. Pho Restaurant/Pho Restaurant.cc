#include <bits/stdc++.h>
using namespace std;

int dp[100000][4][2];

inline void min_update(int& orig, int val) {
	if (orig > val) orig = val;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	vector<vector<int>> v(n);

	bool exist0 = false, exist1 = false;
	for (auto& i : v) {
		string s; cin >> s;
		i.resize(2);
		for (auto& c : s) ++i[c-'0'];
		if (i[0]) exist0 = true;
		if (i[1]) exist1 = true;
	}

	if ((exist0 && !exist1) || (!exist0 && exist1)) {
		cout << 0;
		return 0;
	}

	// base condition
	for (int i = 0; i < n; ++i) for (int j = 0; j < 4; ++j) for (int k = 0; k < 2; ++k)
		dp[i][j][k] = 987654321;	
	dp[0][0b01][0] = v[0][1], dp[0][0b10][1] = v[0][0];

	for (int i = 1; i < n; ++i) for (int cur = 0; cur < 2; ++cur) {
		for (int prv = 1; prv < (1<<2); ++prv) {
			min_update(dp[i][prv | (1<<cur)][cur], min(dp[i-1][prv][0], dp[i-1][prv][1]) + v[i][!cur]);
		}
	}

	cout << min(dp[n-1][0b11][0], dp[n-1][0b11][1]);
}