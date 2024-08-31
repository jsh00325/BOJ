#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);

    ll n; cin >> n;
    if (n == 0) {
        cout << "NO";
        return 0;
    }
    
    while (n > 0) {
        if (n % 3) {
            --n;
            if (n % 3) {
                cout << "NO";
                return 0;
            } else n /= 3;
        } else {
            n /= 3;
        }
    }
    cout << "YES";
}