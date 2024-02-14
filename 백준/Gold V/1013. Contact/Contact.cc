#include <bits/stdc++.h>
using namespace std;

bool chk(string s) {
	if (s.size() < 4 || s[0] != '1' || s[1] != '0' || s.end()[-1] != '1') return false;
	for (int i = 1; i < s.size()-1; ++i) if (s[i] == '1' && s[i-1] == '0' && s[i+1] == '0') return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		if (s.size() < 2 || s.end()[-1] == '0' || s[0] == s[1]) { cout << "NO\n"; continue; }
		
		int prv_st = 0, flag = 1;
		for (int i = 0; i < s.size(); ++i) if (s[i] == '0') {
			int zero_cnt = (i > 0 ? s[i-1] == '0' : 0) + (i+1 < s.size() ? s[i+1] == '0' : 0);
			if (zero_cnt) continue;
			if (prv_st != i  && !chk(s.substr(prv_st, i-prv_st))) flag = 0;
			prv_st = i+2;
		}
		if (prv_st < s.size() && !chk(s.substr(prv_st, s.size()-prv_st))) flag = 0;
		cout << (flag ? "YES" : "NO") << '\n';
	}
}