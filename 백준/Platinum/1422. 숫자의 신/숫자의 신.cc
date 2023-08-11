#include <bits/stdc++.h>
using namespace std;

int k, n;
vector<int> v;

bool cmp(int a, int b) {
	int len_a = to_string(a).size(), len_b = to_string(b).size();
	unsigned long long n_a = a * pow(10, len_b) + b, n_b = b * pow(10, len_a) + a;
	return n_a > n_b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n - k; i++) v.push_back(v[0]);
	sort(v.begin(), v.end(), cmp);
	for (int i : v) cout << i;
}