#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

int solve(string& s, string& t) {
	vector<int> cnt[26];
    FOR(i, t.size()) cnt[t[i] - 'a'].push_back(i);

	int cur = -1, n = 1;
	for (char c : s) {
		vector<int>& cur_cnt = cnt[c - 'a'];
		if (cur_cnt.empty()) return -1;

		int nxt = lower_bound(cur_cnt.begin(), cur_cnt.end(), cur + 1) - cur_cnt.begin();
		if (nxt == cur_cnt.size())
			(n++),(nxt = lower_bound(cur_cnt.begin(), cur_cnt.end(), 0) - cur_cnt.begin());
		cur = cur_cnt[nxt];
	}
	return n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s, t; cin >> s >> t;
	cout << solve(s, t);
}