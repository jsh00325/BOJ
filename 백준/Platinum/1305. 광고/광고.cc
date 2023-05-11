#include <bits/stdc++.h>
using namespace std;

int l; string s;
int f[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> s;
	
	int j = 0;
	for (int i = 1; i < l; i++) {
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	cout << l - f[l - 1];
}