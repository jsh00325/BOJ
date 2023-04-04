#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
#define FOR(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); (i)++)

const int MX = 1e5;
int n, k, arr[MX], cnt[MX], visited;
ll ans;

void init_global() {
	memset(cnt, 0, sizeof(cnt));
	ans = visited = 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	FOR1(t, tc) {
		init_global();
		cin >> n >> k;
		FOR(i, n) cin >> arr[i];

		int j = 0;
		FOR(i, n) {
			while (j < n && visited < k) 
				if (cnt[arr[j++]]++ == 0) visited++;
			if (visited == k) ans += n - j + 1;
			if (--cnt[arr[i]] == 0) visited--;
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}