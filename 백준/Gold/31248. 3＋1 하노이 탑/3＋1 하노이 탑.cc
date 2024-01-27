#include <bits/stdc++.h>
using namespace std;

struct node { char a, b; };
vector<node> v;

int han_3(int n, char st, char mid, char en) {
	if (n == 1) {v.push_back({st, en}); return 1; }
	int ans = han_3(n-1, st, en, mid);
	ans += han_3(1, st, mid, en);
	ans += han_3(n-1, mid, st, en);
	return ans;
}

int han_4(int n, char st, char m1, char m2, char en) {
	if (n == 1) { v.push_back({st, en}); return 1; }
	if (n == 2) { v.push_back({st, m1}), v.push_back({st, en}), v.push_back({m1, en}); return 3; }

	int ans = han_3(n-2, st, m1, m2);
	ans += han_4(2, st, m1, m1, en);
	ans += han_4(n-2, m2, st, m1, en);
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	cout << han_4(n, 'A', 'B', 'C', 'D');
	for (auto x : v) cout << '\n' << x.a << ' ' << x.b;
}