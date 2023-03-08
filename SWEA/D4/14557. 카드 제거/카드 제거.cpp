#include<iostream>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        string s; cin >> s;
        int cnt = 0;
        for (char c : s) if (c =='1') cnt++;
        cout << '#' << t << ' ' << (cnt % 2 ? "yes" : "no") << '\n';
    }
	return 0;
}