#include <bits/stdc++.h>
using namespace std;

vector<int> orig;
bool vst[45];

int check(int bt) {
	int i = bt;
	i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i & 0x0f0f0f0f) + ((i >> 4) & 0x0f0f0f0f);
	i = (i & 0x00ff00ff) + ((i >> 8) & 0x00ff00ff);
	i = (i & 0x0000ffff) + ((i >> 16) & 0x0000ffff);
	if (i != orig.size()) return 0x7fffffff;

	vector<int> v;
	for (int i = 0; i < 25; ++i) if (bt & (1 << i)) v.push_back((i/5)*10 + i%5);
	
	queue<int> q;
	memset(vst, 0, sizeof(vst));

	q.push(v[0]); vst[v[0]] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int curX = q.front() / 10, curY = q.front() % 10; q.pop();
		cnt++;

		for (int dir = 0; dir < 4; ++dir) {
			int nxtX = curX + ("1012"[dir] - '1'), nxtY = curY + ("0121"[dir] - '1');
			if (nxtX < 0 || nxtX >= 5 || nxtY < 0 || nxtY >= 5) continue;
			if ((bt & (1 << (nxtX*5 + nxtY))) == 0) continue;
			if (vst[nxtX*10 + nxtY]) continue;
			q.push(nxtX*10 + nxtY); vst[nxtX*10 + nxtY] = 1; 
		}
	}

	if (cnt != orig.size()) return 0x7fffffff;

	int min_dist = 0x7fffffff;
	do {
		int cur = 0;
		for (int i = 0; i < orig.size(); ++i) {
			cur += abs((orig[i]/10) - (v[i]/10));
			cur += abs((orig[i]%10 - v[i]%10));
		}
		min_dist = min(min_dist, cur);
	} while (next_permutation(v.begin(), v.end()));
	
	return min_dist;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s[5];
	for (int i = 0; i < 5; ++i) cin >> s[i];
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) if (s[i][j] == '*')
		orig.push_back(i*10 + j);

	int ans = 0x7fffffff;
	for (int bt = 0; bt < (1 << 25); ++bt) ans = min(ans, check(bt));
	cout << ans;
}