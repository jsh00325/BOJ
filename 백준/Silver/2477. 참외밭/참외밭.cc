#include <bits/stdc++.h>
using namespace std;

int k, arr[12][2], cnt[5];

int solve() {
	int st = 0;
	if (cnt[1] == 2) st = (cnt[3] == 2 ? 4 : 2);
	else st = (cnt[3] == 2 ? 1 : 3);

	for (int i = 0; i < 12; i++) if (arr[i][0] == st) return i;
}
int solve2(int st) {
	return arr[st][1] * arr[st + 1][1] - arr[st + 3][1] * arr[st + 4][1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i][0] >> arr[i][1];
		arr[6 + i][0] = arr[i][0];
		arr[6 + i][1] = arr[i][1];
		cnt[arr[i][0]]++;
	}
	cout << k * solve2(solve());
}