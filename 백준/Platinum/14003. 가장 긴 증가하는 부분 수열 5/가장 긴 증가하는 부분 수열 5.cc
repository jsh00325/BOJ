#include <bits/stdc++.h>
using namespace std;

int n, dp[1000000];

int get_last_idx(int x) {
	for (int i = n - 1; i >= 0; i--) if (dp[i] == x) return i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> ans = { a[0] };
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (ans[ans.size() - 1] < a[i]) {
			ans.push_back(a[i]);
			dp[i] = ans.size();
		}
		else {
			int idx = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
			ans[idx] = a[i];
			dp[i] = idx + 1;
		}
	}
	cout << ans.size() << '\n';

	vector<int> lis;
	int cur_idx = get_last_idx(ans.size());
	for (int i = cur_idx - 1; i >= 0; i--) {
		if (dp[i] + 1 == dp[cur_idx] && a[i] < a[cur_idx]) {
			lis.push_back(a[cur_idx]);
			cur_idx = i;
		}
	} lis.push_back(a[cur_idx]);
	for (int i = ans.size() - 1; i >= 0; i--) cout << lis[i] << ' ';
}