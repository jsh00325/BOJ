#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
string c[101][101];

string zero(int n) {
	string rslt = "";
	while (n--) rslt += "0";
	return rslt;
}
string sum(string s1, string s2) {
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	if (s1.size() < s2.size()) s1 += zero(s2.size() - s1.size());
	else if (s1.size() > s2.size()) s2 += zero(s1.size() - s2.size());

	string rslt = ""; int add = 0;
	for (int i = 0; i < s1.size(); i++) {
		int summed = s1[i] - '0' + s2[i] - '0' + add;

		rslt += summed % 10 + '0';
		add = summed / 10;
	}
	if (add) rslt += add + '0';
	
	reverse(rslt.begin(), rslt.end());

	return rslt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) c[i][j] = "1";
			else c[i][j] = sum(c[i - 1][j - 1], c[i - 1][j]);
		}
	}
	cout << c[n][m];
}