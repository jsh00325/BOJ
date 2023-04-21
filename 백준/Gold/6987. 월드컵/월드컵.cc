#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int input[6][3], calc[6][3], ans[4];
int score[3][2][3] = { 
	{{1,0,0}, {0,0,1}},
	{{0,1,0}, {0,1,0}},
	{{0,0,1}, {1,0,0}}
};
vector<pii> vs;

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input[i][j];
			calc[i][j] = 0;
		}
	}
}

void solve(int t, int cur) {
	if (cur == vs.size()) {
		for (int i = 0; i < 6; i++) for (int j = 0; j < 3; j++) if (input[i][j] != calc[i][j]) return;
		ans[t] = 1; return;
	}

	int fs = vs[cur].X, se = vs[cur].Y;

	for (int s = 0; s < 3; s++) {
		for (int i = 0; i < 3; i++) calc[fs][i] += score[s][0][i];
		for (int i = 0; i < 3; i++) calc[se][i] += score[s][1][i];

		bool is_ok = true;
		for (int i = 0; i < 3; i++) if (calc[fs][i] > input[fs][i]) is_ok = false;
		for (int i = 0; i < 3; i++) if (calc[se][i] > input[se][i]) is_ok = false;

		if (is_ok) solve(t, cur + 1);

		for (int i = 0; i < 3; i++) calc[fs][i] -= score[s][0][i];
		for (int i = 0; i < 3; i++) calc[se][i] -= score[s][1][i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 6; i++)
		for (int j = i + 1; j < 6; j++)
			vs.push_back({ i, j });
	for (int t = 0; t < 4; t++) {
		init(); solve(t, 0);
	}
	for (int t = 0; t < 4; t++) cout << ans[t] << ' ';
}