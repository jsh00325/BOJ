#include <bits/stdc++.h>
using namespace std;

vector<int> get_fail(const string& s, int len) {
	vector<int> f(len);
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && s[j] != s[i]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	} return f;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
	int n; cin >> n;
	string s; cin >> s;
	vector<int> f = get_fail(s, n);
    cout << n - f[n-1];
}