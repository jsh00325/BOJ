#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> ans(n);
	deque<int> idx(n);
	for (int i = 0; i < n; ++i) idx[i] = i;

	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x == 1) ans[idx.front()] = n-i, idx.pop_front();
		else if (x == 2) {
			int temp = idx.front(); idx.pop_front();
			ans[idx.front()] = n-i, idx.pop_front(), idx.push_front(temp);
		}
		else ans[idx.back()] = n-i, idx.pop_back();
	}
	for (auto x : ans) cout << x << ' ';	
}