#include <bits/stdc++.h>
using namespace std;

int n1, m1, n2, m2;
bool a1[203][103], a2[53][53], temp[53][53];

bool check(int si, int sj) {
	for (int di = 0; di < n2; ++di) for (int dj = 0; dj < m2; ++dj) {
		if (a1[si+di][sj+dj] & a2[di][dj]) return false;
	} return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n1 >> m1;
	for (int i = 0; i < n1; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m1; ++j) a1[50+i][50+j] = s[j]-'0';
	}

	cin >> n2 >> m2;
	for (int i = 0; i < n2; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m2; ++j) a2[i][j] = s[j]-'0';
	}

	int ans = 0x7fffffff;
	for (int turn = 0; turn < 4; ++turn) {
		for (int si = 50-n1; si <= 50+n1; ++si) for (int sj = 50-m1; sj <= 50+m1; ++sj)
            if (check(si, sj)) ans = min(ans, (max(50+n1, si+n2) - min(50, si)) * (max(50+m1, sj+m2) - min(50, sj)));
		
		swap(n2, m2);
		for (int i = 0; i < n2; ++i) for (int j = 0; j < m2; ++j) temp[i][j] = a2[m2-1-j][i];
		memset(a2, 0, sizeof(a2));
		for (int i = 0; i < n2; ++i) for (int j = 0; j < m2; ++j) a2[i][j] = temp[i][j];
	} cout << ans;
}