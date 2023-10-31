#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
struct node { int p, q; };

bool solve(unordered_map<string, vector<node>>& um, ll target, ll limit) {
	ll ans = 0;
	for (auto it : um) {
		ll cur = 0x7fffffff;
		for (auto x : it.second) if (x.q >= target) cur = min(cur, (ll)x.p);

		if (cur == 0x7fffffff) return false;
		else ans += cur;

	} return ans <= limit;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		ll n, b; cin >> n >> b;

		int type_size = 0;
		unordered_map<string, vector<node>> um;
		for (int i = 0; i < n; i++) {
			string type, name; int price, qual;
			cin >> type >> name >> price >> qual;
			um[type].push_back({price, qual});
		}

		ll st = 0, en = 0x3f3f3f3f;
		while (st + 1 < en) {
			ll mid = (st + en) / 2;
			if (solve(um, mid, b)) st = mid;
			else en = mid;
		} cout << st << '\n';
	}
}