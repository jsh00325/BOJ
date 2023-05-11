#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

int n, dp[16][1 << 16];
string arr[16];
vector<int> str[5];

int alp_to_num(char c) {
	switch (c) {
		case 'A': return 0;
		case 'E': return 1;
		case 'I': return 2;
		case 'O': return 3;
		case 'U': return 4;
		default: return -1;
	}
}
int solve(int cur, int visit) {
	if (dp[cur][visit]) return dp[cur][visit];

	string& lst = arr[cur];
	for (int nxt : str[alp_to_num(lst[lst.size() - 1])]) {
		if ((visit >> nxt) & 1) continue;
		dp[cur][visit] = max(dp[cur][visit], solve(nxt, visit | (1 << nxt)) + (int)arr[nxt].size());
	}
	return dp[cur][visit];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR(i, n) {
		cin >> arr[i];
		str[alp_to_num(arr[i][0])].push_back(i);
	}

	int ans = 0;
	FOR(i, n) ans = max(ans, solve(i, 1 << i) + (int)arr[i].size());
	cout << ans;
}