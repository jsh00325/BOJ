#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& v) {
	for (auto& i : v) if (i == 1) return false;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, x; cin >> n;
	vector<int> v(n+1), one_idx;
	for (int i = 0; i <= n; ++i) {
		cin >> v[i];
		if (v[i] == 1) one_idx.push_back(i);
	}
	cin >> x;

	if (one_idx.size() >= 3) cout << "NO";
	else if (one_idx.size() == 2) {
		if (one_idx[0] + x == one_idx[1]) cout << "YES\n" << one_idx[0] << ' ' << one_idx[1];
		else cout << "NO";
	}
	else if (one_idx.size() == 1) {
		if (one_idx[0] + x <= n && v[one_idx[0] + x] >= 1) cout << "YES\n" << one_idx[0] << ' ' << one_idx[0] + x;
		else if (0 <= one_idx[0] - x && v[one_idx[0] - x] > 2) cout << "YES\n" << one_idx[0]-x << ' ' << one_idx[0];
		else cout << "NO";
	}
	else {
		for (int i = 0; i <= n-x; ++i) {
			if (v[i] > 2 && v[i+x] >= 1) {
				cout << "YES\n" << i << ' ' << i + x;
				return 0;
			}
		}
		cout << "NO";
	}
}