#include <bits/stdc++.h>
using namespace std;

int n, arr[20][20], ans = 999;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) arr[i][j] = (s[j] == 'H' ? 0 : 1);
	}

	for (int data = 0; data < (1 << n); data++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int cur_cnt = 0;
			for (int i = 0; i < n; i++) if (arr[i][j] ^ ((data >> i) & 1)) cur_cnt++;
			cnt += min(cur_cnt, n - cur_cnt);
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}