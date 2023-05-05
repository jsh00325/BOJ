#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

int n;
bool arr[15][15];

bool possible(int i, int j) {
	FOR(ni, i) if (arr[ni][j]) return false;
	for (int d = 1; i - d >= 0; d++) {
		if (j - d >= 0 && arr[i - d][j - d]) return false;
		if (j + d < n && arr[i - d][j + d]) return false;
	} return true;
}
int bt(int i, int cnt) {
	if (cnt == n) return 1;
	if (i == n) return 0;
	int ret = 0;
    FOR(j, n) if (possible(i, j)) {
		arr[i][j] = true;
		ret += bt(i + 1, cnt + 1);
		arr[i][j] = false;
	} return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n; cout << bt(0, 0);
}