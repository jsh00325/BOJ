#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> v(n*n), ans;
	for (int i = 0; i < n*n; ++i) cin >> v[i];
	sort(v.begin(), v.end(), [](int& a, int& b) { return a > b; });

	unordered_map<int, int> del_cnt;

	ans.push_back(v[0]);
	for (int i = 1; i < v.size(); ++i) {
		if (del_cnt.find(v[i]) != del_cnt.end() && del_cnt[v[i]] > 0) --del_cnt[v[i]];
		else {
			for (auto& prv : ans) {
				int cur_gcd = __gcd(prv, v[i]);
				if (del_cnt.find(cur_gcd) == del_cnt.end()) del_cnt[cur_gcd] = 2;
				else del_cnt[cur_gcd] += 2;
			}
			ans.push_back(v[i]);
		}
	}
	for (auto x : ans) cout << x << ' ';
}