#include <bits/stdc++.h>
using namespace std;

const int MX = 77777;
bool isDouble[77778], isPrime[77778];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	double n, m; cin >> n >> m;

	for (int i = 2; i <= MX; ++i) isPrime[i] = 1;
	for (int i = 2; i*i <= MX; ++i) if (isPrime[i]) {
		for (int j = i*i; j <= MX; j += i) isPrime[j] = 0;
		for (int k = 1; k*i*i <= MX; ++k) isDouble[k*i*i] = 1;
	}

	int ans = 0;
	for (double i = 1; i <= min(n, m); ++i) if (!isDouble[(int)i])
		ans += (int)sqrt(n/i) * (int)sqrt(m/i);
	cout << ans;
}