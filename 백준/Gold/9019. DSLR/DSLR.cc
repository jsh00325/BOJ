#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

int t, a, b;
bool visit[10000];

string solve(int a, int b) {
	fill(visit, visit + 10000, false);

	queue<pair<int, string>> q;
	q.push({ a, "" }); visit[a] = true;

	while (!q.empty()) {
		int cur = q.front().X; string op = q.front().Y; q.pop();
		if (cur == b) return op;

		int d = cur * 2 % 10000;
		int s = cur == 0 ? 9999 : cur - 1;
		int l = cur < 1000 ? cur * 10 : (cur * 10 + cur / 1000) % 10000;
		int r = cur / 10 + (cur % 10) * 1000;

		if (!visit[d]) { q.push({ d, op + "D" }); visit[d] = true; }
		if (!visit[s]) { q.push({ s, op + "S" }); visit[s] = true; }
		if (!visit[l]) { q.push({ l, op + "L" }); visit[l] = true; }
		if (!visit[r]) { q.push({ r, op + "R" }); visit[r] = true; }
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}
}