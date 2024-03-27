#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1000];
int n, ans[1000];
bool vst[1000];

void solve(int cur, int idx) {
	ans[idx] = cur;

	if (idx == n-1) {
		for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
		exit(0);
	}

	for (auto& nxt : edge[cur]) {
		if (vst[nxt]) continue;
		vst[nxt] = true;
		solve(nxt, idx+1);
		vst[nxt] = false;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = i+1; j < n; ++j) {
			if (s[j] == '+') edge[i].push_back(j);
			else if (s[j] == '-') edge[j].push_back(i);
			else edge[i].push_back(j), edge[j].push_back(i);
		}
	}

	vector<int> v(n);
	for (int i = 0; i < n; ++i) v[i] = i;
	sort(v.begin(), v.end(), [&](const int& a, const int& b) {
		return edge[a].size() > edge[b].size();
	});

	for (auto& st : v) {
		vst[st] = true;
		solve(st, 0);
		vst[st] = false;
	} cout << -1;
}