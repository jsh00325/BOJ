#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;

string a, b;
const ull x = 4000, MOD = 999999999999989;

ull mHash(const vector<ull>& v) {
	ull rslt = 0, xp = 1;
	for (int i = 0; i < 26; ++i) {
		rslt = (rslt + (xp * v[i]) % MOD) % MOD;
		xp = (xp * x) % MOD;
	} return rslt;
}

bool solve(int len) {
	unordered_set<ull> us;
	ull cur_hash;

	vector<ull> a_info(26);
	for (int i = 0; i < len; ++i) a_info[a[i] - 'a']++;
	cur_hash = mHash(a_info); if (us.find(cur_hash) == us.end()) us.insert(cur_hash);

	for (int i = len; i < a.size(); ++i) {
		a_info[a[i] - 'a']++; a_info[a[i-len] - 'a']--;
		cur_hash = mHash(a_info); if (us.find(cur_hash) == us.end()) us.insert(cur_hash);
	}
	
	vector<ull> b_info(26);
	for (int i = 0; i < len; ++i) b_info[b[i] - 'a']++;
	cur_hash = mHash(b_info); if (us.find(cur_hash) != us.end()) return true;

	for (int i = len; i < b.size(); ++i) {
		b_info[b[i] - 'a']++; b_info[b[i-len] - 'a']--;
		cur_hash = mHash(b_info); if (us.find(cur_hash) != us.end()) return true;
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b;
	if (a.size() < b.size()) swap(a, b);

	for (int len = b.size(); len >= 0; --len)
		if (solve(len)) { cout << len; break; }
}