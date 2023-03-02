#include<iostream>
#include<algorithm>
using namespace std;

int cur_level(int node) {
	int lv = 0, temp = 2;
	while (node >= temp) {
		temp <<= 1; lv++;
	}
	return lv;
}
bool is_left_subtree(int node, int lv) {
	return node < (1 << lv) + (1 << lv - 1);
}
int solve(int n, int v) {
	int mx_depth = cur_level(n), left_depth = mx_depth, right_depth = mx_depth;
	if (is_left_subtree(n, mx_depth)) right_depth--;

	if (v == 1) return max(left_depth, right_depth);

	int cur_depth = cur_level(v);
	return cur_depth + (is_left_subtree(v, cur_depth) ? right_depth : left_depth);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, v; cin >> n >> v;
		cout << '#' << i << ' ' << solve(n, v) << '\n';
	}
	return 0;
}