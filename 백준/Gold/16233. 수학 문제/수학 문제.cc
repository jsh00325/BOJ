#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int digit[100001];
void calc_digit(int& rslt, int x) { while (x > 0) rslt += x % 10, x /= 10; }
inline int sum_digit(ll x) { return digit[x / 100000] + digit[x % 100000]; }

ll solve(ll n) {
	if (n % 9) return -1;
	ll x = n - (n % 10) + (n % 10 ? 10 : 0);
	while (x - sum_digit(x) < n) x += 10;
	if (x - sum_digit(x) == n) return x;
	else return -1;	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	for (int i = 1; i <= 100000; ++i) calc_digit(digit[i], i);
	while (T--) { ll n; cin >> n; cout << solve(n) << ' '; }
}