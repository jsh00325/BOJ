#include <bits/stdc++.h>
using namespace std;

bool is_end = false;
int n, m, a, b, ans;
int p[500000];

int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x != y) p[y] = x;
}
bool is_merged(int x, int y) {
	return find(x) == find(y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) p[i] = i;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b; if (is_end) continue;
		if (is_merged(a, b)) {
			ans = i;
			is_end = true;
		}
		else merge(a, b);
	}
	cout << ans;
}