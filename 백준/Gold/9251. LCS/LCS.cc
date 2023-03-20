#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1;
	cin >> str2;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1.at(i-1) == str2.at(j-1)) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << dp[str1.length()][str2.length()];
}