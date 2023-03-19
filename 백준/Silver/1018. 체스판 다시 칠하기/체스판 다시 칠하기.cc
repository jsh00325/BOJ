#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0x7fffffff;
string str[50];

int check(int i, int j) {
	int cnt = 0;
	for (int di = 0; di < 8; di++)
		for (int dj = 0; dj < 8; dj++)
			if (str[i + di][j + dj] == ((di + dj) % 2 ? 'B' : 'W')) cnt++;
	return min(cnt, 64 - cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> str[i];

	for (int i = 0; i < n - 7; i++)
		for (int j = 0; j < m - 7; j++)
			ans = min(ans, check(i, j));
	cout << ans;
}