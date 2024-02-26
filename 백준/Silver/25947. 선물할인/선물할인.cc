#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, b, a;

int solve(const vector<ll>& v) {
	ll cur_val = 0, cur_dis = 0;
	for (int i = 0; i < a; ++i) {
		cur_val += v[i], cur_dis += v[i];
		if (b < cur_val - (cur_dis >> 1)) return i;
	}
	for (int i = a; i < n; ++i) {
		cur_val += v[i], cur_dis += v[i] - v[i-a];
		if (b < cur_val - (cur_dis >> 1)) return i;
	}
	return n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> b >> a;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	cout << solve(v);
}