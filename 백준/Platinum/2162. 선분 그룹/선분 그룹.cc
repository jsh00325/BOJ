#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> line;
#define X first
#define Y second

int n, p[3000];
vector<line> v;

int ccw(pii a, pii b, pii c) {
	int k = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
	return (k != 0 ? (k > 0 ? 1 : -1) : 0);
}
bool is_cross(line a, line b) {
	int a_rel = ccw(a.X, a.Y, b.X) * ccw(a.X, a.Y, b.Y);
	int b_rel = ccw(b.X, b.Y, a.X) * ccw(b.X, b.Y, a.Y);

	if (a_rel == 1 || b_rel == 1) return false;
	if (a_rel == 0 && b_rel == 0)
		if (b.Y < a.X || a.Y < b.X) return false;
	return true;
}
int find(int x) {
	if (p[x] < 0) return x;
	else return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	p[y] += p[x];
	p[x] = y;
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		line temp; cin >> temp.X.X >> temp.X.Y >> temp.Y.X >> temp.Y.Y;
		if (temp.X > temp.Y) swap(temp.X, temp.Y);
		v.push_back(temp);
	}
	fill(p, p + n, -1);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (is_cross(v[i], v[j])) merge(i, j);

	int group_cnt = 0, mx_group = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] > 0) continue;
		group_cnt++;
		if (mx_group < -p[i])mx_group = -p[i];
	}
	cout << group_cnt << '\n' << mx_group;
}