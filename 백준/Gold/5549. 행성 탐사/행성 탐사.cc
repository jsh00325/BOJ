#include <bits/stdc++.h>
using namespace std;

string s[1000];
int cnt[3][1001][1001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> s[i];

	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) for (int ty = 0; ty < 3; ++ty)
		cnt[ty][i][j] = cnt[ty][i-1][j] + cnt[ty][i][j-1] - cnt[ty][i-1][j-1] + (s[i-1][j-1] == "JOI"[ty]);
	
	while (k--) {
		int si, sj, ei, ej; cin >> si >> sj >> ei >> ej;
		for (int ty = 0; ty < 3; ++ty) 
			cout << cnt[ty][ei][ej] - cnt[ty][si-1][ej] - cnt[ty][ei][sj-1] + cnt[ty][si-1][sj-1] << ' ';
		cout << '\n';
	}
}