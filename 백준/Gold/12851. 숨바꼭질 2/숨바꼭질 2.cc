#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

queue<pii> q;
int n, k;
pii visit[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	q.push({ n, 0 }); visit[n] = {0, 1};
	while (!q.empty()) {
		int cur = q.front().X, cur_time = q.front().Y; q.pop();
		if (cur == k) break;

		int nxt_arr[3] = { cur - 1, cur + 1, cur * 2 };
		for (int nxt : nxt_arr) {
			if (nxt < 0 || nxt > 100000) continue;

			if (visit[nxt].Y == 0) {
				q.push({ nxt, cur_time + 1 });
				visit[nxt] = { cur_time + 1, visit[cur].Y };
			}
			else if (visit[nxt].X == cur_time + 1) visit[nxt].Y += visit[cur].Y;
		}
	}
	cout << visit[k].X << '\n' << visit[k].Y;
}