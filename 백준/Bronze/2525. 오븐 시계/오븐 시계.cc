#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	b += c;
	a += b / 60;
	a %= 24;
	b %= 60;
	cout << a << ' ' << b;
}