#include <bits/stdc++.h>
using namespace std;

int n, p, a, b, ans;
stack<int> s[7];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> p;
	while (n--) {
		cin >> a >> b;
		while (!s[a].empty() && s[a].top() > b) {
			s[a].pop(); ans++;
		}
		if (!s[a].empty() && s[a].top() == b) continue;
		s[a].push(b); ans++;
	}
	cout << ans;
}