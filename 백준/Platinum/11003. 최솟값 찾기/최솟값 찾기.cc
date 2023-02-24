#include <bits/stdc++.h>
using namespace std;

int n, l, arr[5000001];
struct cmp {
	bool operator()(const int &a, const int &b) {
		return arr[a] > arr[b];
	}
};
priority_queue<int, vector<int>, cmp> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		pq.push(i);
		while (pq.top() < i - l + 1) pq.pop();
		cout << arr[pq.top()] << ' ';
	}
}