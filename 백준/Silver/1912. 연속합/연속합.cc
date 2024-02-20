#include <iostream>
#include <algorithm>
using namespace std;

int n, a, dp[100003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		dp[i] = max(dp[i-1] + a, a);
	}
	cout << *max_element(dp+1, dp+1+n);
}