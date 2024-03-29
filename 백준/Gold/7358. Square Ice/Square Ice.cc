#include <bits/stdc++.h>
using namespace std;

const int di[4] = {0, -1, 0, 1}, dj[4] = {-1, 0, 1, 0};
int n, arr[20][20];

void init(vector<string>& v) {
	int r = 4*n - 1, c = 4*n + 3;

	for (int i = 0; i < r; ++i) {
		string cur;
		if (i == 0 || i == r-1) {
			for (int j = 0; j < c; ++j) cur.push_back('*');
			v.push_back(cur);
		}
		else {
			cur.push_back('*');
			for (int j = 0; j < c-2; ++j) cur.push_back(' ');
			cur.push_back('*');
			v.push_back(cur);
		}
	}

	for (int i = 1; i < r; i += 4) {
		for (int j = 1; j < c; j += 4) v[i][j] = 'h';
		for (int j = 3; j < c; j += 4) v[i][j] = 'O';
	}

	for (int i = 3; i < r; i += 4) {
		for (int j = 3; j < c; j += 4) v[i][j] = 'h';
	}
}

void solve() {
	vector<string> v;
	init(v);

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (arr[i][j] == 0) continue;

		int r = 4*i + 1, c = 4*j + 3;
		if (arr[i][j] == 1) {
			v[r][c-2] = v[r][c+2] = 'H';
			v[r][c-1] = v[r][c+1] = '-';
		}
		else {
			v[r-2][c] = v[r+2][c] = 'H';
			v[r-1][c] = v[r+1][c] = '|';
		}
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (arr[i][j] != 0) continue;

		int r = 4*i + 1, c = 4*j + 3;
		for (int dir = 0; dir < 4; ++dir) {
			int d1 = (dir == 2 ? 3 : (dir == 3 ? 2 : dir));
			int d2 = (d1 + 1) % 4;

			if (v[r+di[d1]][c+dj[d1]] == '*') continue;
			if (v[r+di[d2]][c+dj[d2]] == '*') continue;
			if (v[r+2*di[d1]][c+2*dj[d1]] == 'H') continue;
			if (v[r+2*di[d2]][c+2*dj[d2]] == 'H') continue;

			v[r+di[d1]][c+dj[d1]] = "-|-|"[d1];
			v[r+di[d2]][c+dj[d2]] = "-|-|"[d2];

			v[r+2*di[d1]][c+2*dj[d1]] = v[r+2*di[d2]][c+2*dj[d2]] = 'H';

			break;
		}
	}

	for (auto& s : v) cout << s << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int tc = 1; ; ++tc) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
		
		cout << "Case " << tc << ":\n\n";
		solve();
		cout << '\n';
	}
}