#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)

const int MX = 5000000;
bool prime[MX+1];
vector<int> v_pr;

void solve2(int x) {
	for (int p : v_pr) {
		if (p * p > x) break;
		while (x % p == 0) {
			cout << p << ' ';
			x /= p;
		}
	}
	if (x > 1) cout << x;
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 2; i <= MX; i++) prime[i] = true;
	for (int i = 2; i * i <= MX; i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= MX; j += i) prime[j] = false;
	}
	for (int i = 2; i * i <= MX; i++) if (prime[i]) v_pr.push_back(i);


	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		solve2(x);
	}
}