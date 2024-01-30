#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int n, k, cnt = 0; cin >> n >> k;
		string s, ans; cin >> s;
		for (int i = 0; i < n; ++i) ans.push_back('.');

		int prv_idx = -1;
		for (int i = 0; i < n; ++i) if (s[i] == 'G' && (prv_idx == -1 || abs(prv_idx - i) > k)) {
			prv_idx = min(i+k, n-1); ans[prv_idx] = 'G'; ++cnt;
		}

		prv_idx = -1;
		for (int i = 0; i < n; ++i) if (s[i] == 'H' && (prv_idx == -1 || abs(prv_idx - i) > k)) {
			for (int d = k; d >= -k; --d) {
				if (d >= 0 && ans[min(i+d, n-1)] == '.') { prv_idx = min(i+d, n-1); ans[prv_idx] = 'H'; ++cnt; break; }
				else if (d < 0 && ans[max(i+d, 0)] == '.') { prv_idx = max(i+d, 0); ans[prv_idx] = 'H'; ++cnt; break; }
			}
		} cout << cnt << '\n' << ans << '\n';
	}
}