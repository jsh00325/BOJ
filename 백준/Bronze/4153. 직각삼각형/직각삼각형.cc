#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int s[3];
		for (int i = 0; i < 3; i++) cin >> s[i];
		sort(s, s + 3); if (s[2] == 0) break;
		if (s[0] * s[0] + s[1] * s[1] == s[2] * s[2]) cout << "right\n";
		else cout << "wrong\n";
	}
}