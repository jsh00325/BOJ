#include <bits/stdc++.h>
using namespace std;


int k, m, n, s_a[2001], s_b[2001], a[2000001], b[2000001];
void solve(int x, int s[], int rslt[]) {
	rslt[0] = rslt[s[x]] = 1;
	for (int len = 1; len < x; len++)
		for (int en = 0; en < x; en++)
			rslt[s[len + en] - s[en]]++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> s_a[i];
		s_a[i + m] = s_a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> s_b[i];
		s_b[i + n] = s_b[i];
	}
	for (int i = 1; i <= 2 * m; i++) s_a[i] += s_a[i - 1];
	for (int i = 1; i <= 2 * n; i++) s_b[i] += s_b[i - 1];

	solve(m, s_a, a);
	solve(n, s_b, b);

	int ans = 0;
	for (int i = 0; i <= k; i++)
		ans += a[i] * b[k - i];
	cout << ans;
}