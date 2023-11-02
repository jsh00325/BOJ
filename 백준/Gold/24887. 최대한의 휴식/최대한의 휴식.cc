#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))

const int DS = 200001;
ll n, m, w[DS], dp[DS], mx[DS];

bool solve(int x) {
	MEM(dp, 0);
	for (int i = 1; i <= x+1; ++i) dp[i] = mx[i]; 
	for (int i = x+2; i <= n; ++i) dp[i] = max(dp[i-1], dp[i-x-1] + w[i]);
	return dp[n] >= m;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> w[i];

	ll sum = 0;
	for (int i = 1; i <= n; ++i) mx[i] = max(mx[i-1], w[i]), sum += w[i];

	if (sum < m) { cout << -1; return 0; }
	if (mx[n] >= m) { cout << "Free!"; return 0; }

	int st = 0, en = n-1;
	while (st + 1 < en) {
		int mid = (st + en) >> 1;
		if (solve(mid)) st = mid;
		else en = mid;
	} cout << st;
}