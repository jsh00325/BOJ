#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int s, d, i, l, n; cin >> s >> d >> i >> l >> n;
	int temp = s + d + i + l;
	if (temp >= 4 * n) cout << 0;
	else cout << (4*n - temp);
}