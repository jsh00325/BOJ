#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node { int idx, val; };

const int MX = 1e5+3;
int dp[MX], from[MX];
bool drop[MX] = {0, 1, 1, 1};

void solve(vector<node>& arr, int cur) {
	if (cur <= 0) return;
	solve(arr, from[cur]);
	if (drop[cur]) cout << arr[cur].idx << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N;
	vector<node> arr(N+1);
	for (int i = 1; i <= N; i++) { arr[i].idx = i-1; cin >> arr[i].val; }
	sort(arr.begin()+1, arr.end(), [](const node& a, const node& b) { return a.val < b.val; });

	for (int i = 4; i <= N; ++i) {
		if (i % 4 == 0) from[i] = i-4, dp[i] = dp[i-4] + (arr[i].val - arr[i-3].val);
		else {
			int use_cur = dp[i-4] + (arr[i].val - arr[i-3].val);
			if (dp[i-1] > use_cur) from[i] = i-4, dp[i] = use_cur;
			else from[i] = i-1, dp[i] = dp[i-1], drop[i] = true;
		}
	}
	cout << dp[N] << '\n', solve(arr, N);
}