#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1e8 + 7;
ll mat[11][11], rslt[11][11];

/* 'mat1 *= mat2' 역할을 하는 함수 */
void mat_times(ll mat1[11][11], ll mat2[11][11], int size) {
	ll temp[11][11] = { 0, };
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++) {
				temp[i][j] += mat1[i][k] * mat2[k][j];
				temp[i][j] %= MX;
			}
	for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) mat1[i][j] = temp[i][j];
}

int pow_2(int k) {
	ll two = 2, ans = 1;
	while (k) {
		if (k % 2) ans = (ans * two) % MX;
		two = (two * two) % MX; k /= 2;
	}
	return ans;
}

int solve(int k, int n) {
	if (k == 0) return pow_2(n);
	if (k >= n) return 1;

	// init matrices
	for (int i = 0; i <= k; i++) for (int j = 0; j <= k; j++) mat[i][j] = 0;
	mat[0][0] = mat[0][k] = 1;
	for (int i = 1; i <= k; i++) mat[i][i - 1] = 1;

	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k; j++)
			rslt[i][j] = (i == j ? 1 : 0);

	int exp = n - k;
	while (exp) {
		if (exp % 2) mat_times(rslt, mat, k + 1);
		mat_times(mat, mat, k + 1); exp /= 2;
	}

	int ans = 0;
	for (int i = 0; i <= k; i++) ans = (ans + rslt[0][i]) % MX;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> k >> n;
		cout << solve(k, n) << '\n';
	}
}