#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> arr[100001];
int n, t, idx, cnt;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		arr[i].first = s;
		arr[i].second = e;
	}

	sort(arr, arr + n, cmp);

	while(idx < n) {
		if (arr[idx].first < t) idx++;
		else {
			t = arr[idx++].second;
			cnt++;
		}
	}
	cout << cnt;
}