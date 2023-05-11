#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)


int N, R, G, B;
ll dp[11][56][56][56];
ll pact[11];

ll comb(int a, int b, int c) {
	return pact[a + b + c] / pact[a] / pact[b] / pact[c];
}
ll solve(int l, int r, int g, int b) {
	if (l > N) return 1;

	ll& ret = dp[l][r][g][b];
	if (ret != -1) return ret;
    
	ret = 0;
    
	// 한가지 색으로
	if (r + l <= R) ret += solve(l + 1, r + l, g, b);
	if (g + l <= G) ret += solve(l + 1, r, g + l, b);
	if (b + l <= B) ret += solve(l + 1, r, g, b + l);

	// 두가지 색으로
	if (l % 2 == 0) {
		int p = l / 2;
		ll cases = comb(p, p, 0);
		if (r + p <= R && g + p <= G) ret += solve(l + 1, r + p, g + p, b) * cases;
		if (r + p <= R && b + p <= B) ret += solve(l + 1, r + p, g, b + p) * cases;
		if (g + p <= G && b + p <= B) ret += solve(l + 1, r, g + p, b + p) * cases;
	}

	// 세가지 색으로
	if (l % 3 == 0) {
		int p = l / 3;
		if (r + p <= R && g + p <= G && b + p <= B)
			ret += solve(l + 1, r + p, g + p, b + p) * comb(p, p, p);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	pact[0] = 1;
	FOR1(i, 10) pact[i] = (ll)i * pact[i - 1];

	cin >> N >> R >> G >> B;
	MEM(dp, -1);
	cout << solve(1, 0, 0, 0);
}