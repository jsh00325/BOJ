#include <bits/stdc++.h>
using namespace std;
struct node { int idx, val; };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<node> v(n);
	for (int i = 0; i < n; ++i) { v[i].idx = i; cin >> v[i].val; }
	sort(v.begin(), v.end(), [](const node& a, const node& b) {
		if (a.val == b.val) return a.idx < b.idx;
		else return a.val < b.val;
	});

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) ans[v[i].idx] = i;
	for (auto x : ans) cout << x << ' ';
}