#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, pre, cur, ic = 1, dc = 1, ans = 0;
	bool isIc = true;
	cin >> n >> pre;
	for (int i = 1; i < n; ++i) {
		cin >> cur;
		if (pre < cur) {
			if (isIc) ++ic;
			else isIc = true, ans = max(ans, dc), ic = 2;
		}
		else if (pre > cur) {
			if (!isIc) ++dc;
			else isIc = false, ans = max(ans, ic), dc = 2;
		} pre = cur;
	} ans = max(ans, (isIc ? ic : dc));
	cout << ans;
}