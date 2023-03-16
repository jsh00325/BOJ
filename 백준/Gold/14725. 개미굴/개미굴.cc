#include <bits/stdc++.h>
using namespace std;

struct Node {
	map<string, Node> child;
};
Node root;

void insert(Node& cur, vector<string>& v, int idx) {
	if (idx == v.size()) return;
	if (cur.child.find(v[idx]) == cur.child.end()) cur.child[v[idx]] = Node();
	insert(cur.child[v[idx]], v, idx + 1);
}
void print(Node& cur, int lv) {
	for (auto it = cur.child.begin(); it != cur.child.end(); it++) {
		for (int i = 0; i < 2 * lv; i++) cout << '-';
		cout << (*it).first << '\n';
		print((*it).second, lv + 1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	while (n--) {
		int k; cin >> k;
		vector<string> v(k);
		for (int i = 0; i < k; i++) cin >> v[i];
		insert(root, v, 0);
	}
	print(root, 0);
}