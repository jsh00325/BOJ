#include <bits/stdc++.h>
using namespace std;

string s;

int solve(int st, int en, int k) {
	if (k > 3) return -1;

	while (st < en && s[st] == s[en]) ++st, --en;
	if (st >= en) return k;
	
	int lcut = solve(st+1, en, k+1), rcut = solve(st, en-1, k+1);
	if (lcut == -1) return rcut;
	if (rcut == -1) return lcut;
	return min(lcut, rcut);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	cout << solve(0, s.size()-1, 0);
}