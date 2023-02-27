#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MX = 1e9 + 7;
ll base = 2, rslt = 1;

void pow2(int x) {
	while (x) {
		if (x & 1) rslt = (rslt * base) % MX;
		base = (base * base) % MX;
		x >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	pow2(n + 2);
	cout << (rslt + MX - 5) % MX;
}