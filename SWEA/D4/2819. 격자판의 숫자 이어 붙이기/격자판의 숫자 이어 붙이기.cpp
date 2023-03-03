#include <iostream>
#include <unordered_set>
using namespace std;

int ans, arr[4][4], di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
unordered_set<int> vst;

inline bool oob(int i, int j) { return i < 0 || j < 0 || i >= 4 || j >= 4; }
void dfs(int i, int j, int len, int n) {
	if (len == 7) {
		if (vst.find(n) == vst.end()) {
			vst.insert(n); ans++;
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int ni = i + di[dir], nj = j + dj[dir];
		if (oob(ni, nj)) continue;
		dfs(ni, nj, len + 1, n * 10 + arr[ni][nj]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> arr[i][j];
		ans = 0; vst.clear();
		
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				dfs(i, j, 1, arr[i][j]);

		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}