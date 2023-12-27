#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
typedef long long ll;
typedef complex<double> cpx;

void FFT(vector<cpx> &f, cpx w) {
	int n = f.size();
	if (n == 1) return;

	vector<cpx> even(n>>1), odd(n>>1);
	for (int i = 0; i < n; ++i) (i % 2 ? odd : even)[i>>1] = f[i];

	FFT(even, w*w), FFT(odd, w*w);

	cpx wp(1, 0);
	for (int i = 0; i < (n >> 1); ++i) {
		f[i] = even[i] + wp * odd[i];
		f[i + (n >> 1)] = even[i] - wp * odd[i];
		wp *= w;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string astr, bstr; cin >> astr >> bstr;
	if (astr == "0" || bstr == "0") { cout << 0; return 0; }

	int n = 1;
	while (n < astr.size()+1 || n < bstr.size()+1) n <<= 1;
	n <<= 1;

	vector<cpx> a(n), b(n), c(n);
	for (int i = 0; i < astr.size(); ++i) a[i] = cpx(astr.end()[-i-1] - '0', 0);
	for (int i = 0; i < bstr.size(); ++i) b[i] = cpx(bstr.end()[-i-1] - '0', 0);
	
	cpx w(cos(2*PI/n), sin(2*PI/n));
	FFT(a, w), FFT(b, w);

	for (int i = 0; i < n; ++i) c[i] = a[i] * b[i];

	FFT(c, cpx(1, 0) / w);
	for (int i = 0; i < n; ++i) {
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}

	stack<int> ans; ll carry = 0;
	for (int i = 0; i < n; ++i) {
		ll cur = c[i].real();
		ans.push((carry + cur) % 10);
		carry = (carry + cur) / 10;
	}
	while (carry > 0) ans.push(carry % 10), carry /= 10;

	bool flag = true;
	while (!ans.empty()) {
		int cur = ans.top(); ans.pop();
		if (cur == 0 && flag) continue;
		if (flag) flag = false;
		cout << cur;
	}
}