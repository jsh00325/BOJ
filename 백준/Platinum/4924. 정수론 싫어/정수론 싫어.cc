#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6, LOW = -987654321;
bool isPrime[MX+1];
vector<int> pv;
int p[MX+1], dp[MX+1];

int solve(int l, int r) {
	dp[l-1] = 0;
	int max_val = INT32_MIN;
	for (int i = l; i <= r; ++i) {
		dp[i] = max(dp[i-1] + p[i], p[i]);
		max_val = max(max_val, dp[i]);
	} return max_val;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 2; i <= MX; ++i) isPrime[i] = 1;
	for (int i = 2; i*i <= MX; ++i) if (isPrime[i])
		for (int j = i*i; j <= MX; j += i) isPrime[j] = 0;
	for (int i = 2; i <= MX; ++i) if (isPrime[i]) pv.push_back(i), p[i] = 1;

	for (int i = 2; i <= MX; ++i) {
		for (auto& x : pv) {
			if (i*x > MX) break;
			if (p[i*x] == 0) p[i*x] = p[i] + p[x];
		}
	}
	p[1] = -1;
	for (int i = 2; i <= MX; ++i) p[i] -= (isPrime[i] ? 3 : 1);

	for (int tc = 1; ; ++tc) {
		int l, u; cin >> l >> u;
		if (l == -1 && u == -1) break;
		cout << tc << ". " << solve(l, u) << '\n';
	}
}