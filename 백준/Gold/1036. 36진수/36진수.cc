#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

inline int conv_36_dec(char c) { return (c <= '9' ? c-'0' : c-'A'+10); }
inline char conv_dec_36(int x) { return (x < 10 ? '0'+x : 'A'+x-10); }

int n, k;
struct SAMYUK {
	string value;

	SAMYUK() { this->value = "0"; }
	SAMYUK(string s) { this->value = s; }

	SAMYUK& operator+= (const SAMYUK& other) {
		string a = this->value, b = other.value, rslt = "";
		reverse(a.begin(), a.end()), reverse(b.begin(), b.end());

		while (a.size() < b.size()) a += '0';
		while (b.size() < a.size()) b += '0';

		int c = 0;
		for (int i = 0; i < a.size(); ++i) {
			int sum = conv_36_dec(a[i]) + conv_36_dec(b[i]) + c;
			rslt += conv_dec_36(sum % 36);
			c = sum / 36;
		}
		if (c) rslt += conv_dec_36(c);
		reverse(rslt.begin(), rslt.end());

		this->value = rslt;
		return *this;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n; 
	vector<SAMYUK> arr(n);
	FOR(i, n) cin >> arr[i].value;
	cin >> k;

	vector<SAMYUK> changed(36); FOR(i, 36) changed[i].value = "0";
	for (SAMYUK& e : arr) {
		string &str = e.value, base = "";
		FOR(idx, str.size()) {
			int cur = conv_36_dec(str[str.size()-1-idx]);
			if (cur < 35) changed[cur] += SAMYUK(conv_dec_36(35-cur) + base);
			base += '0';
		}
	}

	vector<int> v(36); FOR(i, 36) v[i] = i;
	sort(v.begin(), v.end(), [&] (int& a, int& b) {
		const string &sA = changed[a].value, &sB = changed[b].value;
		if (sA.size() == sB.size()) {
			FOR(i, sA.size()) {
				int aic = conv_36_dec(sA[i]), bic = conv_36_dec(sB[i]);
				if (aic > bic) return true;
				else if (aic < bic) return false;
			} return false;
		} else return sA.size() > sB.size();
	});

	SAMYUK ans;
	FOR(i, n) ans += arr[i];
	FOR(i, k) ans += changed[v[i]];
	cout << ans.value;
}