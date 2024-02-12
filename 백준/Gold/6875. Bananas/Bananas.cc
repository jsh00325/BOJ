#include <bits/stdc++.h>
using namespace std;

bool is_A(int st_idx, int len);
bool is_M(int st_idx, int len);

string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (true) {
		cin >> s;
		if (s == "X") break;
		cout << (is_M(0, s.size()) ? "YES" : "NO") << '\n';
	}
}

bool is_A(int st_idx, int len) {
	if (len == 1 && s[st_idx] == 'A') return true;
	if (len >= 3 && s[st_idx] == 'B' && s[st_idx+len-1] == 'S') return is_M(st_idx+1, len-2);
	return false;
}
bool is_M(int st_idx, int len) {
	if (is_A(st_idx, len)) return true;
	else {
		for (int i = 1; i < len - 1; ++i) 
			if (s[st_idx + i] == 'N' && is_A(st_idx, i) && is_M(st_idx+i+1, len-i-1)) return true;
	}
	return false;
}