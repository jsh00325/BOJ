#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;

		int g = 0, h = 0; string g_first, h_first;
		for (int i = 0; i < n; ++i) g_first.push_back('.'), h_first.push_back('.');

		int g_idx = -1, h_idx = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'G' && (g_idx == -1 || abs(g_idx - i) > k)) { g_idx = min(i+k, n-1); g_first[g_idx] = 'G'; ++g; }
			if (s[i] == 'H' && (h_idx == -1 || abs(h_idx - i) > k)) { h_idx = min(i+k, n-1); h_first[h_idx] = 'H'; ++h; }
		}

		g_idx = -1, h_idx = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'H' && (h_idx == -1 || abs(h_idx - i) > k)) {
				for (int d = k; d >= -k; --d) {
					if (d >= 0 && g_first[min(i+d, n-1)] == '.') { h_idx = min(i+d, n-1); g_first[h_idx] = 'H'; ++g; break; }
					else if (d < 0 && g_first[max(i+d, 0)] == '.') { h_idx = max(i+d, 0); g_first[h_idx] = 'H'; ++g; break; }
				}
			}
			if (s[i] == 'G' && (g_idx == -1 || abs(g_idx - i) > k)) {
				for (int d = k; d >= -k; --d) {
					if (d >= 0 && h_first[min(i+d, n-1)] == '.') { g_idx = min(i+d, n-1); h_first[g_idx] = 'G'; ++h; break; }
					else if (d < 0 && h_first[max(i+d, 0)] == '.') { g_idx = max(i+d, 0); h_first[g_idx] = 'G'; ++h; break; }
				}
			}
		}
		if (g <= h) cout << g << '\n' << g_first << '\n';
		else cout << h << '\n' << h_first << '\n';
	}
	
}