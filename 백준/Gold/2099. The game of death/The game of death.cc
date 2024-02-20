#include <bits/stdc++.h>
using namespace std;

int n, k, m;
struct mat {
	int a[200][200];
	mat() { memset(a, 0, sizeof(a)); }

	mat operator* (const mat& other) {
		mat ans;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)	{
			for (int k = 0; k < n; ++k) if (a[i][k] * other.a[k][j]) {
				ans.a[i][j] = 1; break;
			}
		}
		return ans;
	}
} base, rslt;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> m;
	for (int i = 1; i <= n; ++i) {
		int a, b; cin >> a >> b;
		base.a[i-1][a-1] = base.a[i-1][b-1] = 1;
	}

	for (int i = 0; i < n; ++i) rslt.a[i][i] = 1;
	while (k > 0) {
		if (k & 1) rslt = rslt * base;
		base = base * base; k >>= 1;
	}

	while (m--) {
		int a, b; cin >> a >> b;
		cout << (rslt.a[a-1][b-1] ? "death" : "life") << '\n';
	}	
}