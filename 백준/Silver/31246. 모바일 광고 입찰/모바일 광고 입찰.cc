#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		v[i] = b - a;
	} sort(v.begin(), v.end());

	cout << (v[k-1] > 0 ? v[k-1] : 0);
}