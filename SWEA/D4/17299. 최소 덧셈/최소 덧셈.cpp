#include <iostream>
#include <string>
using namespace std;
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); (i)++)

int solve(string& s) {
	int mid = s.size() / 2;
	int ans = stoi(s.substr(0, mid)) + stoi(s.substr(mid, s.size()-mid));
	if (s.size() % 2 == 0) return ans;
	else return min(ans, stoi(s.substr(0, mid+1)) + stoi(s.substr(mid+1, s.size() - mid - 1)));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	int t; cin >> t; FOR1(tc, t) {
		string s; cin >> s;
		cout << '#' << tc << ' ' << solve(s) << '\n';
	}
}