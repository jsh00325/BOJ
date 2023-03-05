#include <bits/stdc++.h>
using namespace std;

struct node {
	double x, y;
};
struct vertex {
	double w;
	int from, to;
};

int n, p[100], cnt;
vector<vertex> edge;
node point[100];

bool cmp(const vertex& a, const vertex& b) {
	return a.w < b.w;
}

int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x != y) p[y] = x;
}
bool is_merged(int x, int y) {
	return find(x) == find(y);
}
double get_dist(const node &a, const node &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> point[i].x >> point[i].y;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			edge.push_back({ get_dist(point[i], point[j]), i, j });
	sort(edge.begin(), edge.end(), cmp);

	for (int i = 0; i < n; i++) p[i] = i;

	double ans = 0;
	for (vertex v : edge) {
		if (find(v.from) == find(v.to)) continue;
		ans += v.w;
		merge(v.from, v.to);
		if (++cnt == n - 1) break;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;
}