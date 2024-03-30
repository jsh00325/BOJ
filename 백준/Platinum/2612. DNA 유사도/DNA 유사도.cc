#include <bits/stdc++.h>
using namespace std;

string sa, sb;
int a, b, lcs[1001][1001], from[1001][1001];
bool vsta[1001], vstb[1001];
// 0: 왼쪽, 1: 위쪽, 2: 대각선, -1: 새로 시작
const int di[3] = {0, -1, -1}, dj[3] = {-1, 0, -1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> a >> sa >> b >> sb;
	sa = " " + sa, sb = " " + sb;

	for (int i = 1; i <= a; ++i) for (int j = 1; j <= b; ++j) {
		if (sa[i] == sb[j]) {
			lcs[i][j] = max(lcs[i][j], lcs[i-1][j-1] + 3);
			from[i][j] = (lcs[i-1][j-1] ? 2 : -1);
		}
		else {
			if (lcs[i-1][j-1] && lcs[i][j] < lcs[i-1][j-1] - 2)
				lcs[i][j] = lcs[i-1][j-1] - 2, from[i][j] = 2;
			if (lcs[i-1][j] && lcs[i][j] < lcs[i-1][j] - 2)
				lcs[i][j] = lcs[i-1][j] - 2, from[i][j] = 1;
			if (lcs[i][j-1] && lcs[i][j] < lcs[i][j-1] - 2)
				lcs[i][j] = lcs[i][j-1] - 2, from[i][j] = 0;
			
			if (lcs[i][j] < 0) lcs[i][j] = 0, from[i][j] = -1;
		}
	}

	int mi, mj, mv = -1;
	for (int i = 1; i <= a; ++i) for (int j = 1; j <= b; ++j)
		if (lcs[i][j] > mv) mi = i, mj = j, mv = lcs[i][j];
	cout << mv << '\n';
		
	string ra = "", rb = "";
	while (true) {
		vsta[mi] = vstb[mj] = 1;

		int& cur_from = from[mi][mj];
		if (cur_from == -1) break;

		mi += di[cur_from], mj += dj[cur_from];
	}

	for (int i = 1; i <= a; ++i) if (vsta[i]) cout << sa[i];
	cout << '\n';

	for (int i = 1; i <= b; ++i) if (vstb[i]) cout << sb[i];
	cout << '\n';
}