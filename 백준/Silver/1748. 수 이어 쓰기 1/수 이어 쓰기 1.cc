#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, len;
long long ans;
int jarisu(int num) {
	int cnt = 0;
	while (num) {
		num /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	len = jarisu(n);

	for (int i = 1; i < len; i++)
		ans += 9 * pow(10, i-1) * i;
	ans += (n - (pow(10, len-1)-1)) * len;
	
	cout << ans;
}