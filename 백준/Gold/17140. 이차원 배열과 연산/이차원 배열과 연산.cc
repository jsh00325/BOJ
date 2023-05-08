#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

int r, c, k;
int n = 3, m = 3, arr[103][103], cnt[103];
vector<int> v;

bool cmp(const int& x, const int& y) {
	if (cnt[x] == cnt[y]) return x < y;
	else return cnt[x] < cnt[y];
}

void row_sort() {
	int mx_m = 0;
	FOR(i, n) {
		v.clear(); MEM(cnt, 0);
		FOR(j, m) if (arr[i][j] && (cnt[arr[i][j]]++) == 0) v.push_back(arr[i][j]);
		FOR(j, m) arr[i][j] = 0;
		sort(v.begin(), v.end(), cmp);
		int cur_m = min(50, (int)v.size());
		FOR(vi, cur_m) {
			arr[i][vi * 2] = v[vi];
			arr[i][vi * 2 + 1] = cnt[v[vi]];
		}
		mx_m = max(mx_m, cur_m * 2);
	} m = mx_m;
}
void column_sort() {
	int mx_n = 0;
	FOR(j, m) {
		v.clear(); MEM(cnt, 0);
		FOR(i, n) if (arr[i][j] && (cnt[arr[i][j]]++) == 0) v.push_back(arr[i][j]);
		FOR(i, n) arr[i][j] = 0;
		sort(v.begin(), v.end(), cmp);
		int cur_n = min(50, (int)v.size());
		FOR(vi, cur_n) {
			arr[vi * 2][j] = v[vi];
			arr[vi * 2 + 1][j] = cnt[v[vi]];
		}
		mx_n = max(mx_n, cur_n * 2);
	}
	n = mx_n;
}
int solve() {
	for (int t = 0; t <= 100; t++) {
		if (r < n && c < m && arr[r][c] == k) return t;
		if (n >= m) row_sort();
		else column_sort();
	} return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c >> k;
	FOR(i, 3) FOR(j, 3) cin >> arr[i][j];
	r--; c--;
	cout << solve();
}