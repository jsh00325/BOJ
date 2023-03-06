#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string s; cin >> s;
		int exp = s.size() - 1;
		string f = s.substr(0, 2);
		if (s[2] >= '5') f[1]++;
		if (f[1] > '9') { f[1] = '0'; f[0]++; }
		if (f[0] > '9') { f[0] = '1'; exp++; }

		cout << '#' << t << ' ' << f[0] << '.' << f[1] << "*10^" << exp << '\n';
	}
	return 0;
}