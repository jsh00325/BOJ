#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

const int MX = 10001;
pii cood[MX];

int solve(const pii& a, const pii& b) {
	int dx = b.X - a.X, dy = b.Y - a.Y;
	if (dx * dy <= 0) return abs(dx) + abs(dy);
	else return max(abs(dx), abs(dy));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt = 1;
	for (int i = 1; cnt < MX; i++)
		for (int j = 1; j <= i; j++) {
			cood[cnt++] = { i, j };
			if (cnt == MX) break;
		}

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int a, b; cin >> a >> b;
		cout << '#' << t << ' ' << solve(cood[a], cood[b]) << '\n';
	}
	return 0;
}