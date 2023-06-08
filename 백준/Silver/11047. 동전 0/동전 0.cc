#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a[11], cnt, now;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	now = n;
	while (k > 0) {
		if (k < a[now]) now--;
		else {
			k -= a[now];
			cnt++;
		}
	}
	cout << cnt;
}