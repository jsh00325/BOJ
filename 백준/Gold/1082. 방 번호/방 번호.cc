#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

int n, m, cost[10], ansDigit;
string ans = "0";

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n; FOR(i, n) cin >> cost[i]; cin >> m;

	for (int st = 1; st < n; ++st) if (m >= cost[st]) {
		int mnNum = 0;
		for (int x = 1; x < n; ++x) if (cost[mnNum] >= cost[x]) mnNum = x;
		int curDigit = (m - cost[st]) / cost[mnNum];

		if (curDigit < 0 || ansDigit > curDigit + 1) continue;

		string head = "", temp = ""; head += ('0' + st);
		FOR(x, curDigit) temp += ('0' + mnNum);
		int money = m - cost[st] - curDigit * cost[mnNum];

		int upgradeNum = n - 1;
		for (int idx = 0; idx < curDigit; ++idx) {
			while (upgradeNum > mnNum && money < cost[upgradeNum] - cost[mnNum]) --upgradeNum;
			if (upgradeNum == mnNum) break;
			temp[idx] = ('0' + upgradeNum), money -= cost[upgradeNum] - cost[mnNum];
		}
		
		ansDigit = curDigit + 1, ans = head + temp;
	}
	cout << ans;	
}