#include <iostream>
#include <algorithm>
using namespace std;

int n, k, st, lng, cmp;

int main() {
	cin >> n >> k;

	lng = 1; cmp = 10;
	for (int i = 1; i <= n; i++) {
		st += lng;
		if (k < st) {
			int num = i-1;
			for (int idx = 1; idx < st - k; idx++) num /= 10;
			cout << num % 10;
			return 0;
		}

		if (i == cmp) {
			lng++; cmp *= 10;
		}		
	}

	if (k >= st + lng) cout << -1;
	else {
		for (int idx = 1; idx < st + lng - k; idx++) n /= 10;
		cout << n % 10;
	}
}