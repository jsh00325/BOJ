#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	int tp = 1;
	for (int i = 1; n >= tp; i++) {
		tp *= 10;
		int st = tp / 10, en = min(n, tp - 1);
		ans += i * (en - st + 1);
	}
	cout << ans;
}