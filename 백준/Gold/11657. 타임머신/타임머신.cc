#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, m;
ll d[503];
vector<pair<pii, int>> edge;

bool bellman_ford() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int from = edge[j].X.X;
			int to = edge[j].X.Y;
			int w = edge[j].Y;

			if (d[from] != INF && d[to] > d[from] + w) {
				if (i == n) return false;
				d[to] = d[from] + w;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge.push_back({ {a, b}, c });
	}

	fill(d + 1, d + n + 1, INF); d[1] = 0;

	if (!bellman_ford()) cout << -1;
	else for (int i = 2; i <= n; i++) cout << (d[i] == INF ? -1 : d[i]) << '\n';
}