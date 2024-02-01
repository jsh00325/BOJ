#include <bits/stdc++.h>
using namespace std;
#define DF(i, j, n) for (int (i) = 1; (i) < (n)-1; ++(i)) for (int (j) = 1; (j) < (n)-1; ++(j))

int arr[10][10], info[10][10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];
	DF(i, j, n) for (int k = 0; k < 5; ++k) info[i][j] += arr[i+("01112"[k]-'1')][j+("10121"[k]-'1')];

	int ans = 0x7fffffff;
	DF(fi, fj, n) DF(si, sj, n) if (abs(fi-si) + abs(fj-sj) >= 3) DF(ti, tj, n)
		if (abs(fi-ti) + abs(fj-tj) >= 3 && abs(si-ti) + abs(sj-tj) >= 3) ans = min(ans, info[fi][fj]+info[si][sj]+info[ti][tj]);
	cout << ans;
}