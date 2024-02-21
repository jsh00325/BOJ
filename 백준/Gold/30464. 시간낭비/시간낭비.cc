#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;
int n, a[MX], table[MX][2][3];
vector<int> front_from[MX], back_from[MX];

int dp(int idx, int dir, int cnt) {
	int& ret = table[idx][dir][cnt];
	if (ret != -1) return ret;
	if (idx == n-1 && dir != 0) return ret = -2;

	for (auto& fr : front_from[idx]) {
		if (dir == 0) ret = max(ret, dp(fr, 0, cnt) + 1);
		else if (cnt > 0) ret = max(ret, dp(fr, 0, cnt-1) + 1);
	}
	for (auto& bk : back_from[idx]) {
		if (dir == 1) ret = max(ret, dp(bk, 1, cnt) + 1);
		else if (cnt > 0) ret = max(ret, dp(bk, 1, cnt-1) + 1);
	}

	return (ret == -1 ? ret = -2 : ret);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) { cin >> a[i]; if (a[i] == 0) a[i] = 987654321; }
	for (int i = 0; i < n; ++i) if (i + a[i] < n) front_from[i + a[i]].push_back(i);
	for (int i = n-1; i >= 0; --i) if (i - a[i] >= 0) back_from[i - a[i]].push_back(i);

	memset(table, -1, sizeof(table));
	table[0][0][0] = 0;

	int ans = max(dp(n-1, 0, 0), dp(n-1, 0, 2));
	cout << (ans == -2 ? -1 : ans);
}