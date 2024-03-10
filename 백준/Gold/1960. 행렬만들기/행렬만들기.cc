#include <bits/stdc++.h>
using namespace std;

int n;
bool arr[500][500];
vector<int> row, col;
struct node { int idx, cnt; };

bool solve() {
	vector<node> colv(n);
	for (int j = 0; j < n; ++j) colv[j] = {j, col[j]};

	for (int i = 0; i < n; ++i) {
		if (row[i] > n) return false;

		sort(colv.begin(), colv.end(), [](const node& a, const node& b) {
			if (a.cnt == b.cnt) return a.idx < b.idx;
			else return a.cnt > b.cnt;
		});

		for (int k = 0; k < row[i]; ++k) {
			if (colv[k].cnt == 0) return false;
			arr[i][colv[k].idx] = 1;
			--colv[k].cnt;
		}
	}

	for (auto& v : colv) if (v.cnt > 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	row.resize(n), col.resize(n);
	for (auto& i : row) cin >> i;
	for (auto& i : col) cin >> i;

	if (solve()) {
		cout << 1;
		for (int i = 0; i < n; ++i) {
			cout << '\n';
			for (int j = 0; j < n; ++j) cout << arr[i][j];
		}
	}
	else cout << -1;
}