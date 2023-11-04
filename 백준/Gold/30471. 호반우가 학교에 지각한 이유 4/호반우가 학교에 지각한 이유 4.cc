#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
struct node { int x, y; };

const int MX = 200000;
ll a[MX+1], ans;
int n, m, p[MX+1];

int find(int x) {
	if (p[x] < 0) return x;
	else return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;

	ans -= a[-p[x]] + a[-p[y]];

	if (p[x] <= p[y]) {
		p[x] += p[y]; p[y] = x;
		ans += a[-p[x]];
	}
	else {
		p[y] += p[x]; p[x] = y;
		ans += a[-p[y]];
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	a[1] = 1;
	for (int i = 2; i <= MX; ++i) a[i] = a[i-1] + i;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) p[i] = -1;
	ans = n;
	while (m--) {
		int a, b; cin >> a >> b;
		merge(a, b); cout << ans << '\n';
	}
}