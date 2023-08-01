#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, s;

// 공집합도 포함하기(두개로 나눴을때, 한 그룹에서 공집합이 있는 경우도 생각해야함)
vector<int> sum_of_subsequence(const vector<int> &x) {
	vector<int> rslt;
	for (int i = 0; i < (1 << x.size()); i++) {
		int nxt = 0;
		for (int j = 0; j < x.size(); j++) if ((i >> j) & 1) nxt += x[j];
		rslt.push_back(nxt);
	} sort(rslt.begin(), rslt.end());
	return rslt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	vector<int> a, b;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (i % 2) a.push_back(x);
		else b.push_back(x);
	}
	vector<int> sub_a = sum_of_subsequence(a), sub_b = sum_of_subsequence(b);

	ll ans = 0;
	for (int cur : sub_a)
		ans += upper_bound(sub_b.begin(), sub_b.end(), s - cur) - lower_bound(sub_b.begin(), sub_b.end(), s - cur);
	if (s == 0) ans--;
	cout << ans;
}