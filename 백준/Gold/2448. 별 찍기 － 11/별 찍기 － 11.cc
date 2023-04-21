#include <bits/stdc++.h>
using namespace std;

int n;
char board[3072][6143];

void draw(int i, int j) {
	board[i][j] = '*';
	board[i + 1][j - 1] = board[i + 1][j + 1] = '*';
	for (int d = -2; d <= 2; d++) board[i + 2][j + d] = '*';
}
void solve(int n, int i, int j) {
	if (n == 3) return draw(i, j);

	solve(n / 2, i, j);
	solve(n / 2, i + n / 2, j - n / 2);
	solve(n / 2, i + n / 2, j + n / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) fill(board[i], board[i] + n*2 - 1, ' ');
	solve(n, 0, n-1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n*2 - 1; j++) cout << board[i][j];
		cout << '\n';
	}
}