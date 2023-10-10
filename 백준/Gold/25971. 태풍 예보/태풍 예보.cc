#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define X first
#define Y second

ll n, k, r, q, j, x, y;
pll typhoon[200002];
ll di[4] = { 1, 0, -1, 0 }, dj[4] = { 0, 1, 0, -1 };

string solve(ll day, ll x, ll y) {
	if ((typhoon[day].X - x) * (typhoon[day].X - x) + (typhoon[day].Y - y) * (typhoon[day].Y - y) > r * r) return "gori";

	if (typhoon[day].X == typhoon[day + 1].X) {
		if (typhoon[day].X == x) return "gori";

		if (typhoon[day].Y < typhoon[day + 1].Y) {
			if (typhoon[day].X < x) return "unsafe";
			else return "safe";
		}
		else {
			if (typhoon[day].X < x) return "safe";
			else return "unsafe";
		}
	}
	else {
		if (typhoon[day].Y == y) return "gori";

		if (typhoon[day].X < typhoon[day + 1].X) {
			if (typhoon[day].Y < y) return "safe";
			else return "unsafe";
		}
		else {
			if (typhoon[day].Y < y) return "unsafe";
			else return "safe";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> r >> q;
	int prev = 0;
	for (int i = 0; i < k; i++) {
		int day, x, y; cin >> day >> x >> y;

		if (i == 0) {
			prev = day;
			typhoon[day] = { x, y };
			continue;
		}

		ll direction = typhoon[prev].Y == y ? (typhoon[prev].X < x ? 0 : 2) : (typhoon[prev].Y < y ? 1 : 3);
		for (int temp = prev + 1; temp <= day; temp++) {
			typhoon[temp].X = typhoon[temp - 1].X + di[direction];
			typhoon[temp].Y = typhoon[temp - 1].Y + dj[direction];
		}
		prev = day;
	}
	typhoon[n + 1].X = typhoon[n].X * 2 - typhoon[n - 1].X;
	typhoon[n + 1].Y = typhoon[n].Y * 2 - typhoon[n - 1].Y;

	while (q--) {
		cin >> j >> x >> y;
		cout << solve(j, x, y) << '\n';
	}
}