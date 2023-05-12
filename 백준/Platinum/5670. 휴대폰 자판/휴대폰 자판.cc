#include <bits/stdc++.h>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

const int ROOT = 1, MX = 1e6+5;
int n, unused = 2;
bool isEnd[MX];
int nxt[MX][26];

void init_trie() {
	unused = 2;
	MEM(isEnd, false);
	isEnd[ROOT] = true;
	MEM(nxt, -1);
}

void insert(string& s) {
	int cur = ROOT;
	for (char c : s) {
		if (nxt[cur][c - 'a'] == -1)
			nxt[cur][c - 'a'] = unused++;
		cur = nxt[cur][c - 'a'];
	}
	isEnd[cur] = true;
}
int count_typing(int cur, int cnt) {
	int child = 0;
	FOR(i, 26) child += (nxt[cur][i] != -1);

	int ret = (isEnd[cur] ? cnt : 0);
	FOR(i, 26) if (nxt[cur][i] != -1)
		ret += count_typing(nxt[cur][i], cnt + (child > 1 || isEnd[cur]));
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed; cout.precision(2);

	while (cin >> n) {
		init_trie();
		FOR(i, n) { string s; cin >> s; insert(s); }
		cout << (double)count_typing(ROOT, 0) / n << '\n';
	}
}