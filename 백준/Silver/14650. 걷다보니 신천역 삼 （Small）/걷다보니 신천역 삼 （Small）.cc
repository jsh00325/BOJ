#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	if (n == 1) cout << 0;
	else cout << 2 * pow(3, n - 2);
}