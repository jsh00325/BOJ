#include <iostream>
using namespace std;

int arr[101][101];
int di[4] = { 0, 1, 0, -1 }, dj[4] = { 1, 0, -1, 0 };

void fill(int i, int j, int n, int s) {
	if (n <= 0) return;

	for (int dir = 0; dir < 4; dir++) {
		for (int k = 0; k < n - 1; k++) {
			arr[i][j] = s++;
			i += di[dir];
			j += dj[dir];
		}
	}
	if (n == 1) arr[i][j] = s++;
	fill(i + 1, j + 1, n - 2, s);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n; cin >> n;
		cout << '#' << t << '\n';
		fill(0, 0, n, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << arr[i][j] << ' ';
			cout << '\n';
		}
	}
	return 0;
}