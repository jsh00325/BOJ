#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
bool isPrime[MX+1], ans[MX+1];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 2; i <= MX; ++i) isPrime[i] = 1;
	for (int i = 2; i*i <= MX; ++i) if (isPrime[i])
		for (int j = i*i; j <= MX; j += i) isPrime[j] = 0;

	int n, k; cin >> n >> k;
	for (int i = k+1; i <= n; ++i) if (isPrime[i])
		for (int j = i; j <= n; j += i) ans[j] = 1;

	int cnt = 0;
	for (int i = 1; i <= n; ++i) cnt += (ans[i] == 0);
	cout << cnt;	
}