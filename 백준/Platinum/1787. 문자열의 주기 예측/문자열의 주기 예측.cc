#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> get_fail(const string& s, int len) {
	vector<int> f(len);
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	} return f;
}
vector<int> get_min_border(const vector<int>& f, int len) {
	vector<int> m(f);
	for (int i = 0; i < len; i++) {
		if (m[i] == 0) continue;
		while (m[m[i] - 1]) m[i] = m[m[i] - 1];
	} return m;
}
ll solve(const vector<int>& min_border, int len) {
	ll sum = 0;
	for (int i = 0; i < len; i++)
		if (min_border[i]) sum += i + 1 - min_border[i];
	return sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	vector<int> f = get_fail(s, n);
	vector<int> mn = get_min_border(f, n);
	cout << solve(mn, n);
}