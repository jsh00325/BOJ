#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

int arr[4][1000];

inline void update(int& ans, int& ans_diff, int cur, int cur_diff) {
	if (ans_diff > cur_diff) ans = cur, ans_diff = cur_diff;
	else if (ans_diff == cur_diff && ans > cur) ans = cur;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int k, n; cin >> k >> n;
		FOR(i, 4) FOR(j, n) cin >> arr[i][j];
		vector<int> sum34;
		FOR(c3, n) FOR(c4, n) sum34.push_back(arr[2][c3] + arr[3][c4]);
		sort(sum34.begin(), sum34.end());

		int ans = 0, ans_diff = 0x7fffffff;
		FOR(c1, n) FOR(c2, n) {
			int cur = arr[0][c1] + arr[1][c2];
			auto it = lower_bound(sum34.begin(), sum34.end(), k - cur);
			
			if (it != sum34.begin()) update(ans, ans_diff, cur + (*(it-1)), abs(k - cur - (*(it-1))));
			if (it != sum34.end()) update(ans, ans_diff, cur + (*it), abs(k - cur - (*it)));
		} 
		cout << ans << '\n';
	}
}