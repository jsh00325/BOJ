#include <bits/stdc++.h>
using namespace std;

int n1, m1, n2, m2;
bool a1[103][103], a2[103][103], temp[103][103];

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
		for (int j = 0; j < m1; ++j) a1[i][j] = s[j]-'0';
	}

	cin >> n2 >> m2;
	for (int i = 0; i < n2; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m2; ++j) a2[i][j] = s[j]-'0';
	}

	int ans = 0x7fffffff;
	for (int turn = 0; turn < 4; ++turn) {
		for (int si = 0; si <= n1; ++si) for (int sj = 0; sj <= m1; ++sj)
            if (check(si, sj)) ans = min(ans, max(n1, si+n2) * max(m1, sj+m2));
		
		swap(n2, m2);
		for (int i = 0; i < n2; ++i) for (int j = 0; j < m2; ++j) temp[i][j] = a2[m2-1-j][i];
		for (int i = 0; i < n2; ++i) for (int j = 0; j < m2; ++j) a2[i][j] = temp[i][j];
	} cout << ans;
}