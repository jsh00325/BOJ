#include <bits/stdc++.h>
using namespace std;

int arr[201];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		memset(arr, 0, sizeof(arr));
		int n; cin >> n;
		while (n--) {
			int a, b; cin >> a >> b;
			if (a > b) swap(a, b);
			arr[(a - 1) / 2]++;
			arr[(b - 1) / 2 + 1]--;
		}
		for (int i = 1; i <= 200; i++) arr[i] += arr[i - 1];
		
		cout << '#' << t << ' ' << *max_element(arr, arr+200) << '\n';
	}
	return 0;
}