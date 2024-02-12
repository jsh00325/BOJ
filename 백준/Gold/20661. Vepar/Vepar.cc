#include <bits/stdc++.h>
using namespace std;

const int MX = 1e7;
bool isPrime[MX+1];
vector<int> pv;

int ch(int p, int n) {
	int ret = 0;
	while (p <= n) ret += n/p, n /= p;
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 2; i <= MX; ++i) isPrime[i] = 1;
	for (int i = 2; i*i <= MX; ++i) if (isPrime[i])
		for (int j = i*i; j <= MX; j += i) isPrime[j] = 0;
	for (int i = 2; i <= MX; ++i) if (isPrime[i]) pv.push_back(i);

	int T; cin >> T;
	while (T--) {
		int a, b, c, d; cin >> a >> b >> c >> d;		
		bool flag = true;
		for (int i = 0; i < pv.size(); ++i)
			if (ch(pv[i], b)-ch(pv[i], a-1) > ch(pv[i], d)-ch(pv[i], c-1)) { flag = false; break; }
		cout << (flag ? "DA" : "NE") << '\n';
	}	
}