#include <bits/stdc++.h>
using namespace std;

int n, q, t, a, rmax, rcnt, cmax, ccnt;
vector<int> r, c;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	r.resize(n+1), c.resize(n+1), rcnt = ccnt = n;
	while (q--) {
		cin >> t >> a;
		if (t == 1) {
			++r[a];
			if (r[a] > rmax) rmax = r[a], rcnt = 1;
			else if (r[a] == rmax) ++rcnt;
		}
		else {
			++c[a];
			if (c[a] > cmax) cmax = c[a], ccnt = 1;
			else if (c[a] == cmax) ++ccnt;
		}
		cout << rcnt * ccnt << '\n';
	}
}