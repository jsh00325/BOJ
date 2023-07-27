#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for(register int (i) = 0; (i) < (n); ++(i))
#define FOR1(i, n) for(register int (i) = 1; (i) <= (n); ++(i))

constexpr int MOD = 1e9+7, MX = 2000;
int h, w, n, m, fir_pow[MX], sec_pow[MX];
int s[3][MX][MX], t[3][MX][MX];

void set_hash_table(int a[3][MX][MX], int r, int c) {
	// 가로 해시 설정 (a[1][~][~] 채우기)
	FOR(i, r) {
		FOR(j, w) if (a[0][i][j]) a[1][i][0] += fir_pow[w - j - 1];
		FOR1(j, c - w) a[1][i][j] = (a[1][i][j - 1] - a[0][i][j - 1] * fir_pow[w - 1]) * fir_pow[1] + a[0][i][j + w - 1];
	}

	// 세로 해시 설정 (a[2][~][~] 채우기)
	FOR(j, c - w + 1) {
		FOR(i, h) a[2][0][j] += a[1][i][j] * sec_pow[h - i - 1];
		FOR1(i, r - h) a[2][i][j] = (a[2][i - 1][j] - a[1][i - 1][j] * sec_pow[h - 1]) * sec_pow[1] + a[1][i + h - 1][j];
	}
}

int solve() {
	cin >> h >> w >> n >> m;
	string st; int ans = 0;
	MEM(s, 0), MEM(t, 0);
	FOR(i, h) { cin >> st; FOR(j, w) t[0][i][j] = (st[j] == 'o'); }
	FOR(i, n) { cin >> st; FOR(j, m) s[0][i][j] = (st[j] == 'o'); }
	set_hash_table(t, h, w), set_hash_table(s, n, m);

	FOR(i, n - h + 1) FOR(j, m - w + 1) if (s[2][i][j] == t[2][0][0]) ans++;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	fir_pow[0] = sec_pow[0] = 1;
	FOR1(i, MX - 1) fir_pow[i] = fir_pow[i - 1] * 3;
	FOR1(i, MX - 1) sec_pow[i] = sec_pow[i - 1] * 103;

	int t; cin >> t;
	FOR1(tc, t) cout << '#' << tc << ' ' << solve() << '\n';
}