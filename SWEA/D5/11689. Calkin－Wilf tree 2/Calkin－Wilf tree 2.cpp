#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> a >> b;
		ans = 0;
		while (!(a == 1 && b == 1)) {
			if (a > b) swap(a, b);
			if (a == 1) (ans += b - a), (b = 1);
			else (ans += b / a), (b %= a);
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}