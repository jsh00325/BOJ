#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int n, q, g;
ll m, price[100], cnt[100];
string a, h_nam[100];
vector<int> group[101];
unordered_map<string, int> nam_2_num;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		cin >> g >> h_nam[i] >> price[i];
		nam_2_num[h_nam[i]] = i;
		group[g].push_back(i);
	}

	for (int qr = 0; qr < q; ++qr) {
		int op, b, c, d, e; cin >> op;
		if (op == 1) {
			cin >> a >> b;
			int h_num = nam_2_num[a];
			if (price[h_num] * b > m) continue;
			m -= price[h_num] * b, cnt[h_num] += b;
		}
		else if (op == 2) {
			cin >> a >> b;
			int h_num = nam_2_num[a];
			if (cnt[h_num] == 0) continue;
			m += price[h_num] * min((ll)b, cnt[h_num]), cnt[h_num] -= min((ll)b, cnt[h_num]);
		} 
		else if (op == 3) {
			cin >> a >> c;
			price[nam_2_num[a]] += c;
		}
		else if (op == 4) {
			cin >> d >> c;
			for (int& h_num : group[d]) price[h_num] += c;
		}
		else if (op == 5) {
			cin >> d >> e;
			for (int& h_num : group[d]) price[h_num] = (price[h_num] * (100 + e)) / 1000 * 10;
		}
		else if (op == 6) cout << m << '\n';
		else {
			ll ans = m;
			for (int i = 0; i < n; ++i) ans += price[i] * cnt[i];
			cout << ans << '\n';
		}
	}
}