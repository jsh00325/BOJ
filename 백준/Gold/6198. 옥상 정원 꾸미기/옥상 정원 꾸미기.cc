#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second

ll ans;
int n, result[80001];
stack<pii> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	fill(result, result + n, n);
	for (int i = 0; i < n; i++) {
		int cur; cin >> cur;

		while (!s.empty()) {
			if (s.top().Y > cur) break;
			result[s.top().X] = i; s.pop();
		}
		s.push({ i, cur });
	}
	for (int i = 0; i < n; i++) ans += result[i] - i - 1;
	cout << ans;
}