#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> msTree[200003];

void merge(vector<int>& dist, const vector<int>& a, const vector<int> &b) {
	int i = 0, j = 0;
	while (i < a.size() && j < b.size())
		if (a[i] < b[j]) dist.push_back(a[i++]);
		else dist.push_back(b[j++]);
	while (i < a.size()) dist.push_back(a[i++]);
	while (j < b.size()) dist.push_back(b[j++]);
}

inline int count(const vector<int>& v, int k) {
	return v.end() - upper_bound(v.begin(), v.end(), k);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n; int x;
	for (int i = 0; i < n; ++i) cin >> x, msTree[i+n].push_back(x);
	for (int i = n - 1; i >= 1; --i) merge(msTree[i], msTree[i<<1], msTree[i<<1|1]);

	int q, last_ans = 0; cin >> q;
	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		last_ans = [] (int l, int r, int k) {
			int ret = 0;
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l & 1) ret += count(msTree[l++], k);
				if (r & 1) ret += count(msTree[--r], k);
			} return ret;
		} ((a ^ last_ans) - 1, b ^ last_ans, c ^ last_ans);
		cout << last_ans << '\n';
	}
}