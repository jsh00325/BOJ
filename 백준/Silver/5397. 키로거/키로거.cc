#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		list<char> l = {};
		auto it = l.begin();

		string s; cin >> s;
		for (char c : s) {
			if (c == '<') { if (it != l.begin()) it--; }
			else if (c == '>') { if (it != l.end()) it++; }
			else if (c == '-') {
				if (it != l.begin()) {
					it--;
					it = l.erase(it);
				}
			}
			else l.insert(it, c);
		}
		for (auto c : l) cout << c;
		cout << '\n';
	}
}