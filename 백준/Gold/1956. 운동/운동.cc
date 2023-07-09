#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int v, e, d[403][403], ans = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 1; i <= v; i++) fill(d[i]+1, d[i]+v+1, INF);
	while (e--) {
		int a, b, c; cin >> a >> b >> c;
		d[a][b] = c;
	}

	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

	for (int i = 1; i <= v; i++) {
		if (d[i][i] == INF) continue;
		ans = min(ans, d[i][i]);
	}

	if (ans == INF) cout << -1;
	else cout << ans;
}