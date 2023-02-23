#include <bits/stdc++.h>
using namespace std;

char arr[400][400];
void fill(int i, int j, int len, char c) {
	for (int di = 0; di < len; di++) arr[i + di][j] = arr[i + di][j + len - 1] = c;
	for (int dj = 0; dj < len; dj++) arr[i][j + dj] = arr[i + len - 1][j + dj] = c;
}
void solve(int i, int j, int n) {
	fill(i, j, 4 * n - 3, '*');
	if (n == 1) return;
	fill(i + 1, j + 1, 4 * n - 5, ' ');
	solve(i + 2, j + 2, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	solve(0, 0, n);
	for (int i = 0; i < 4 * n - 3; i++) {
		for (int j = 0; j < 4 * n - 3; j++) cout << arr[i][j];
		cout << '\n';
	}
}