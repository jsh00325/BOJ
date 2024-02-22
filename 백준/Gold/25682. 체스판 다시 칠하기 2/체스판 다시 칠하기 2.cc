#include <bits/stdc++.h>
using namespace std;

int n, m, k, f[2000][2000][2];
string arr[2000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	f[0][0][0] = (arr[0][0] == 'W');
	for (int c = 1; c < m; ++c) f[0][c][0] = f[0][c-1][0] + (arr[0][c] == (c % 2 ? 'B' : 'W'));
	for (int r = 1; r < n; ++r) f[r][0][0] = f[r-1][0][0] + (arr[r][0] == (r % 2 ? 'B' : 'W'));

	for (int r = 1; r < n; ++r) for (int c = 1; c < m; ++c)
		f[r][c][0] = f[r-1][c][0] + f[r][c-1][0] - f[r-1][c-1][0] + (arr[r][c] == ((r+c) % 2 ? 'B' : 'W'));
	
	f[0][0][1] = (arr[0][0] == 'B');
	for (int c = 1; c < m; ++c) f[0][c][1] = f[0][c-1][1] + (arr[0][c] == (c % 2 ? 'W' : 'B'));
	for (int r = 1; r < n; ++r) f[r][0][1] = f[r-1][0][1] + (arr[r][0] == (r % 2 ? 'W' : 'B'));

	for (int r = 1; r < n; ++r) for (int c = 1; c < m; ++c)
		f[r][c][1] = f[r-1][c][1] + f[r][c-1][1] - f[r-1][c-1][1] + (arr[r][c] == ((r+c) % 2 ? 'W' : 'B'));

	int ans = 0x7fffffff;
	for (int r = k-1; r < n; ++r) for (int c = k-1; c < m; ++c) {
		int topB = f[r][c][0], topW = f[r][c][1];
		if (r-k >= 0) topB -= f[r-k][c][0], topW -= f[r-k][c][1];
		if (c-k >= 0) topB -= f[r][c-k][0], topW -= f[r][c-k][1];
		if (r-k >= 0 && c-k >= 0) topB += f[r-k][c-k][0], topW += f[r-k][c-k][1];

		ans = min(ans, min(topB, topW));
	}
	cout << ans;
}