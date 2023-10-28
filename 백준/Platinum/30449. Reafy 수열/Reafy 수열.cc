#include <bits/stdc++.h>
using namespace std;

bool gcdTable[5001][5001];
struct node {
	int t, b;
	bool operator< (const node& other) {
		return t * other.b < b * other.t;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) for (int j = i; j <= n; ++j) gcdTable[i][j] = true;
	for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) for (int k = j; k <= n; k += i)
		gcdTable[j][k] = false;

	vector<node> v = {{0,1}, {1,1}};
	for (int bot = 2; bot <= n; ++bot)
		for (int top = 1; top < bot; ++top)
			if (gcdTable[top][bot]) v.push_back({top, bot});
	nth_element(v.begin(), v.begin()+k-1, v.end());
	cout << v[k-1].t << ' ' << v[k-1].b;
}