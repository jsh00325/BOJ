#include <iostream>
using namespace std;

int cnt[10001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	while (n--) {
		int x; cin >> x; cnt[x]++;
	}
	for (int i = 1; i <= 10000; i++) 
		for (int k = 0; k < cnt[i]; k++) cout << i << '\n';
}