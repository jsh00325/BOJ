#include <bits/stdc++.h>
using namespace std;

struct Trie_node {
	map<char, Trie_node> child;
	bool end;
} cl_root, nm_root;

void insert(Trie_node& cur, const string& s, int sIdx) {
	if (sIdx == s.size()) { cur.end = true; return; }
	if (cur.child.find(s[sIdx]) == cur.child.end()) cur.child[s[sIdx]] = Trie_node();
	insert(cur.child[s[sIdx]], s, sIdx+1);
}

void find(unordered_set<int>& rslt, Trie_node& cur, const string& s, int sIdx) {
	if (s.size() == sIdx) return;
	if (cur.end) rslt.insert(sIdx);
	if (cur.child.find(s[sIdx]) != cur.child.end()) find(rslt, cur.child[s[sIdx]], s, sIdx+1);
}

bool ans(unordered_set<int>& us1, unordered_set<int>& us2, int target) {
	for (auto x : us1) if (us2.find(target - x) != us2.end()) return true;
	return false;	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int c, n; cin >> c >> n;
	string s;
	for (int i = 0; i < c; ++i) { cin >> s; insert(cl_root, s, 0); }
	for (int i = 0; i < n; ++i) { cin >> s; reverse(s.begin(), s.end()); insert(nm_root, s, 0); }

	int q; cin >> q;
	while (q--) {
		cin >> s;
		unordered_set<int> cl_us, nm_us;
		find(cl_us, cl_root, s, 0);
		reverse(s.begin(), s.end());
		find(nm_us, nm_root, s, 0);

		cout << (ans(cl_us, nm_us, s.size()) ? "Yes" : "No") << '\n';
	}
}