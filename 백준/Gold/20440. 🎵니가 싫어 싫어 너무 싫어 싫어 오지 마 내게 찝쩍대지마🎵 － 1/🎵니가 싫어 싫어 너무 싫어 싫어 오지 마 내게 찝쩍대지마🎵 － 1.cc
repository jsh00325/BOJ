#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
struct node { int s, e; };

const int MX = 2'000'005;
int arr[MX + 5];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<node> v(n);
	vector<int> coord;
	FOR(i, n) {
		cin >> v[i].s >> v[i].e;
		coord.push_back(v[i].s), coord.push_back(v[i].e);
	}

	sort(coord.begin(), coord.end());
	coord.erase(unique(coord.begin(), coord.end()), coord.end());

	unordered_map<int, int> compressed;
	for (int i = 0; i < coord.size(); ++i) compressed[coord[i]] = i;

	for (node& c : v) ++arr[compressed[c.s]], --arr[compressed[c.e]];

	int mxValue = arr[0];
	for (int i = 1; i < MX; i++)
		arr[i] += arr[i-1], mxValue = max(mxValue, arr[i]);

	bool flag = false;
	int stPoint, enPoint;
	FOR(i, MX) {
		if (arr[i] == mxValue && !flag) stPoint = i, flag = true;
		else if (arr[i] != mxValue && flag) { enPoint = i; break; }
	}

	cout << mxValue << '\n';
	cout << coord[stPoint] << ' ' << coord[enPoint];
}