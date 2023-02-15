#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> m;
bool cmp(const vector<int> &x, const vector<int> &y) { return x.size() < y.size(); }

void set_failure(vector<int> &f, const vector<int> &t, int t_idx) {
	fill(f.begin(), f.end(), 0);
	int j = 0;
	for (int i = 1; i < k; i++) {
		while (j > 0 && t[t_idx + i] != t[t_idx + j]) j = f[j - 1];
		if (t[t_idx + i] == t[t_idx + j]) f[i] = ++j;
	}
}
bool kmp(const vector<int> &s, const vector<int> &t, int t_idx, vector<int>& f) {
	set_failure(f, t, t_idx);
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != t[t_idx + j]) j = f[j - 1];
		if (s[i] == t[t_idx + j]) j++;
		if (j == k) return true;
	}
	j = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		while (j > 0 && s[i] != t[t_idx + j]) j = f[j - 1];
		if (s[i] == t[t_idx + j]) j++;
		if (j == k) return true;
	}
	return false;
}
string solve() {
	if (m[0].size() < k) return "NO";
	
	vector<int> f(k);
	for (int i = 0; i <= m[0].size() - k; i++) {
		bool is_poss = true;
		for (int j = 1; j < n && is_poss; j++) is_poss = kmp(m[j], m[0], i, f);
		if (is_poss) return "YES";
	}
	return "NO";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int mi; cin >> mi;
		vector<int> temp(mi);
		for (int j = 0; j < mi; j++) cin >> temp[j];
		m.push_back(temp);
	}
	sort(m.begin(), m.end(), cmp);
	cout << solve();
}