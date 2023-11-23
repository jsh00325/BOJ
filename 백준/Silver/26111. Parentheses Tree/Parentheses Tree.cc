#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s; cin >> s;
	stack<char> st; st.push(s[0]);
	long long ans = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '(') st.push('(');
		else { st.pop(); if(s[i-1] == '(') ans += st.size(); }
	} cout << ans;
}