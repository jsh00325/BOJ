#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> OS;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> v(n), ans(n);
	for (int i = 0; i < n; ++i) cin >> v[i], OS.insert(i);

	int temp = v.end()[-1] % (n - 1);
	swap(v[0], v[temp]);

	int m = 0, p = n;
	for (int i = 0; i < n; ++i) {
		int idx = *(OS.find_by_order(m));
		OS.erase(idx);
		ans[idx] = v[i];
		if (i == n-1) break;
		m = (v[i] + m - 1) % (--p);
	}
	for (auto& x : ans) cout << x << '\n';
}