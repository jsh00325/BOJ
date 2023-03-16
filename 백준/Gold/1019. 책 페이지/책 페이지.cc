#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll ans[10];

void func1(int x, ll w) {
	while (x) {
		ans[x % 10] += w;
		x /= 10;
	}
}
void solve(int st, int en, ll w) {
	if (st == en) return func1(st, w);
	if (en < 10) {
		for (int i = st; i <= en; i++) ans[i] += w;
		return;
	}
	while (en % 10 != 9) {
		func1(en, w);
		if ((en--) == st) return;
	}
	for (int i = 0; i < 10; i++)
		ans[i] += (ll)(en / 10 - st / 10 + 1) * w;
	solve(st / 10, en / 10, w * 10);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
	cin >> n;
	for (int i = 1; n >= i; i *= 10)
		solve(i, min(i * 10 - 1, n), 1);
	for (int i = 0; i < 10; i++) cout << ans[i] << ' ';
}