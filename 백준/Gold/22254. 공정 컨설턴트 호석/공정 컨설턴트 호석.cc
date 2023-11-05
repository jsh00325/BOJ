#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

struct cmp { bool operator() (const int& a, const int& b) { return a > b; } };
priority_queue<int, vector<int>, cmp> pq;

bool solve(int x) {
	if (x == 0) return false;
	bool ans = true;
	for (auto cur : v) {
		if (pq.size() < x) pq.push(cur);
		else {
			int pt = pq.top(); pq.pop();
			pq.push(pt + cur);
			if (pt + cur > k) ans = false;
		}
	}
	while (!pq.empty()) pq.pop();
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	v.resize(n); for (int i = 0; i < n; ++i) cin >> v[i];

	int st = 0, en = n;
	while (st + 1 < en) {
		int mid = (st + en) / 2;
		if (solve(mid)) en = mid;
		else st = mid;
	} cout << en;
}