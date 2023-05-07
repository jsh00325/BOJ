#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

int n, arr[10][10];
bool visit[10][10];

bool possible(int i, int j) {
	while ((--i) >= 0 && (--j) >= 0)
		if (visit[i][j]) return false;
	return true;
}
int bt(int l, int cnt) {
	if (l >= 2 * n) return cnt;

	int si, sj;
	if (l <= n) (si = 0), (sj = l - 1);
	else (si = l - n), (sj = n - 1);

	int ret = 0;
	do {
		if (arr[si][sj] == 1 && possible(si, sj)) {
			visit[si][sj] = 1;
			ret = max(ret, bt(l + 2, cnt + 1));
			visit[si][sj] = 0;
		}
		si++; sj--;
	} while (si < n && sj >= 0);
	ret = max(ret, bt(l + 2, cnt));
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR(i, n) FOR(j, n) cin >> arr[i][j];
	cout << bt(1, 0) + bt(2, 0);
}