#include <bits/stdc++.h>
using namespace std;
int a, b, n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b >> n;

	if (a % 10 == 9) {
		if ((b / 10) % 2 == 0) cout << -1;
		else if ((b / 10) == 5) cout << -1;
		else {
			cout << a << 7;
			for (int i = 0; i < n-5; ++i) cout << 1;
			cout << b;
		}
	}
	else {
		if ((b / 10) % 2 == 0) cout << -1;
		else if ((b / 10) == 5) cout << -1;
		else {
			cout << a;
			for (int i = 0; i < n-4; ++i) cout << 1;
			cout << b;
		}
	}
}