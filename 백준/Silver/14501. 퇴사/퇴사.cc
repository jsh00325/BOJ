#include <iostream>
#include <algorithm>
using namespace std;

int n, t[20], p[20], d[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];
	d[n+1] = 0;
	for (int i = n; i >= 1; i--) {
		if (i+t[i] <= n+1) d[i] = max(p[i]+d[i+t[i]], d[i+1]);
		else d[i] = d[i+1];
	}
	cout << d[1];
}