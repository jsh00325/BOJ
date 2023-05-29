#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); ++(i))

const int MX = 360000;
int n, x, f[MX];
bool text[2 * MX], pattern[MX];

void set_fail() {
	int j = 0;
	for (int i = 1; i < MX; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = f[j - 1];
		if (pattern[i] == pattern[j]) f[i] = ++j;
	}
}
bool find() {
	int j = 0;
	FOR(i, 2 * MX) {
		while (j > 0 && text[i] != pattern[j]) j = f[j - 1];
		if (text[i] == pattern[j]) j++;
		if (j == MX) return true;
	} return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR(i, n) { cin >> x; text[x] = text[x + MX] = 1; }
	FOR(i, n) { cin >> x; pattern[x] = 1; } set_fail();
	cout << (find() ? "possible" : "impossible");
}