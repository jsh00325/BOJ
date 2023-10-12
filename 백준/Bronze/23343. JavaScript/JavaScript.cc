#include <bits/stdc++.h>
using namespace std;
 
bool check(string& s) {
	for (char c : s) if (c < '0' || c > '9') return false;
	return true;
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b; cin >> a >> b;
	if (!check(a) || !check(b)) cout << "NaN";
	else cout << stoi(a) - stoi(b);	
}