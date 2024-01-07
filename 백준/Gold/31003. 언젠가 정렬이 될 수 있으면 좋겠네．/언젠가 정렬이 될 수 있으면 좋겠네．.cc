#include <bits/stdc++.h>
using namespace std;

int n, arr[3000], ind[3000];
vector<int> edge[3000];

struct cmp { bool operator() (const int& a, const int& b) { return arr[a] > arr[b]; }};
priority_queue<int, vector<int>, cmp> pq;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n-1; ++i) for (int j = i+1; j < n; ++j)
		if (__gcd(arr[i], arr[j]) != 1) edge[i].push_back(j), ++ind[j];
	
	for (int i = 0; i < n; ++i) if (ind[i] == 0) pq.push(i);

	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		cout << arr[cur] << ' ';

		for (int& nxt : edge[cur]) {
			if (--ind[nxt] == 0) pq.push(nxt);
		}
	}
}