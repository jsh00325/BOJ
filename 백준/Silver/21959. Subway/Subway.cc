#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node { int x, y; };

const int MX = 44721;
ll arr[MX+1];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll k; cin >> k;

	if (k == 0) {
		cout << "1\n0 -1";
		return 0;
	}

	vector<node> v; v.push_back({0, -1});
	for (int i = 2; i <= MX; ++i) arr[i] = arr[i-1] + i-1;

	for (int cur = MX; cur >= 2; --cur)  {
		for (int j = 0; j < (k / arr[cur]); ++j) {
			int prev = 0, nxt = v.size();
			for (int i = 1; i < cur; ++i) {
				v.push_back({nxt, prev});
				prev = nxt, nxt = v.size();
			}
		} k %= arr[cur];
	}
	cout << v.size() << '\n';
	for (auto x : v) cout << x.x << ' ' << x.y << '\n';
}