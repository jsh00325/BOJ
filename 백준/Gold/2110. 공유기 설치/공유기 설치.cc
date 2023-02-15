#include <bits/stdc++.h>
using namespace std;

int n, c;
bool solve(int x, vector<int> &v) {
	int prev = v[0], cnt = 1;
	for (int i = 1; i < v.size(); i++)
		if (v[i] - prev >= x) {
			prev = v[i];
            cnt++;
		}
	return cnt >= c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	sort(x.begin(), x.end());

	int st = 1, en = x[x.size()-1] - x[0];
	while (st < en) {
		int mid = (st + en + 1) / 2;

		if (solve(mid, x)) st = mid;
		else en = mid - 1;
	}
	cout << st;
}