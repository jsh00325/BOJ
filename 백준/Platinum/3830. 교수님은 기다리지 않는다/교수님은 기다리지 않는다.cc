#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)

const int MX = 100003;
int n, m, a, b, w, p[MX]; char op;
ll d[MX];

int find(int x) {
	if (x == p[x]) return x;
	int pX = find(p[x]);
	d[x] += d[p[x]];
	return p[x] = pX;
}
void merge(int x, int y, int w) {
	int xP = find(x), yP = find(y);
	if (xP == yP) return;
	p[yP] = xP;
	d[yP] = d[x] - d[y] + (ll)w;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		FOR1(i, n) p[i] = i; MEM(d, 0);
		
		FOR(i, m) {
			cin >> op >> a >> b;
			if (op == '!') {
				cin >> w;
				merge(a, b, w);
			}
			else {
				if (find(a) == find(b))
					cout << d[b] - d[a] << '\n';
				else cout << "UNKNOWN\n";
			}
		}
	}
}