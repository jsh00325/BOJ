#include <iostream>
#include <algorithm>
using namespace std;

int n, a, cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 1) continue;
		bool isTrue = true;
		for (int i = 2; i * i <= a; i++)
			if (a % i == 0) isTrue = false;
		if (isTrue) cnt++;
	}
	cout << cnt;
}