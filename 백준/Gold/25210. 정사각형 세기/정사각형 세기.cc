#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct { int x, y; } Node;
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)

const int MX = 2 * 1e5 + 3;
Node p[5][3], a, b, c, d;
int ak, bk, ck, dk;
ll cnt[2][2 * MX + 1];

ll solve() {
	if (a.x < b.x || c.x < d.x || a.y > b.y || c.y > d.y) return 0;
	ak = a.y - a.x; bk = b.y - b.x; ck = c.y - c.x; dk = d.y - d.x;
	if (ak > bk || ck > dk) return 0;
	ll ans = 0;
	int mab = min(a.x - b.x, b.y - a.y) + 1;
	int mcd = min(c.x - d.x, d.y - c.y) + 1;
	FOR1(de, mab) cnt[0][ak + de - 1 + MX] = cnt[0][bk - de + 1 + MX] = de;
	FOR1(de, mcd) cnt[1][ck + de - 1 + MX] = cnt[1][dk - de + 1 + MX] = de;
	for (int k = ak; k <= bk; k++) if (cnt[0][k + MX] == 0) cnt[0][k + MX] = mab;
	for (int k = ck; k <= dk; k++) if (cnt[1][k + MX] == 0) cnt[1][k + MX] = mcd;
	for (int k = max(ak, ck); k <= min(bk, dk); k++) ans += cnt[0][k + MX] * cnt[1][k + MX];
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	FOR1(i, 4) FOR1(j, 2) cin >> p[i][j].x >> p[i][j].y;
	a = { min(p[2][1].x, p[3][1].x), max(p[3][2].y, p[4][2].y) };
	b = { max(p[2][2].x, p[3][2].x), min(p[3][1].y, p[4][1].y) };
	c = { min(p[1][2].x, p[4][2].x), max(p[1][1].y, p[2][1].y) };
	d = { max(p[1][1].x, p[4][1].x), min(p[1][2].y, p[2][2].y) };
	cout << solve();
}