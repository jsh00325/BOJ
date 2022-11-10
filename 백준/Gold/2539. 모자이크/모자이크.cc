#include <bits/stdc++.h>
using namespace std;

int h, w, n, m, mx_height;
vector<int> cord;

// 길이가 x인 색종이로 덮을 수 있을까?
bool solve(int x) {
	int cnt = 0, prev_end = 0;
	for (int c : cord) {
		if (c < prev_end) continue;
		if (++cnt > n) return false;
		prev_end = c + x;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		mx_height = max(mx_height, x);
		cord.push_back(y);
	}
	sort(cord.begin(), cord.end());
	cord.erase(unique(cord.begin(), cord.end()), cord.end());


	int st = mx_height, en = h;
	while (st < en) {
		int mid = (st + en) / 2;

		if (solve(mid)) en = mid;
		else st = mid + 1;
	}
	cout << st;
}