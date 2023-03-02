#include<iostream>
using namespace std;
typedef long long ll;

int cnt = 0;
void solve(ll x, ll n) {
	if (cnt >= 50) return;
	x *= 10;
	for (int i = (x ? 0 : 1); i < 10; i++) {
		if (x + i > n || cnt >= 50) return;
		cout << x + i << ".png ";
		if (++cnt >= 50) return;
		solve(x + i, n);
	}
}

int main(int argc, char** argv)
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		ll n; cin >> n;
		cout << '#' << i << ' ';
		cnt = 0;
		solve(0, n);
		cout << '\n';
	}
	return 0;
}