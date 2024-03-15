#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
struct node { int i, j, val; };

void change_value(int i, int j, int cur, int nxt, vvi& row_cnt, vvi& col_cnt) {
	--row_cnt[i][cur], --col_cnt[j][cur];
	++row_cnt[i][nxt], ++col_cnt[j][nxt];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vvi row_cnt(n), col_cnt(n);
		for (int i = 0; i < n; ++i) row_cnt[i].resize(n+1), col_cnt[i].resize(n+1);

		vvi v(n);
		for (int i = 0; i < n; ++i) {
			v[i].resize(n);
			for (int j = 0; j < n; ++j) {
				cin >> v[i][j];
				++row_cnt[i][v[i][j]], ++col_cnt[j][v[i][j]];
			}
		}

		vector<bool> row_uni(n), col_uni(n);
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			for (int x = 1; x <= n; ++x) cnt += (row_cnt[i][x] > 0);
			row_uni[i] = (cnt == n);
		}
		for (int j = 0; j < n; ++j) {
			int cnt = 0;
			for (int x = 1; x <= n; ++x) cnt += (col_cnt[j][x] > 0);
			col_uni[j] = (cnt == n);
		}

		vector<node> ans;
		// cross check
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (row_uni[i] && col_uni[j]) {
			int nxt = (v[i][j] % n) + 1;
			change_value(i, j, v[i][j], nxt, row_cnt, col_cnt);
			row_uni[i] = col_uni[j] = false;
			v[i][j] = nxt;
			ans.push_back({i+1, j+1, nxt});
		}

		// independent check
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (row_uni[i] || col_uni[j]) {
			for (int nxt = 1; nxt <= n; ++nxt) {
				change_value(i, j, v[i][j], nxt, row_cnt, col_cnt);
				bool row_chk = false, col_chk = false;
				for (int k = 1; k <= n; ++k) {
					if (row_cnt[i][k] == 0) row_chk = true;
					if (col_cnt[j][k] == 0) col_chk = true;
				}

				if (row_chk && col_chk) {
					row_uni[i] = col_uni[j] = false;
					v[i][j] = nxt;
					ans.push_back({i+1, j+1, nxt});
					break;
				}
				else change_value(i, j, nxt, v[i][j], row_cnt, col_cnt);
			}
		}

		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x.i << ' ' << x.j << ' ' << x.val << '\n';
	}
}