#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

const int MX = 1e6;
int n, m, arr[MX], prefix[MX+1], cnt[1000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    FOR(i, n) cin >> arr[i], arr[i] %= m;
    FOR1(i, n) prefix[i] = (prefix[i-1] + arr[i-1]) % m, cnt[prefix[i]]++;
    ll ans = (ll)cnt[0] * (cnt[0] + 1) / 2;
    FOR1(i, m - 1) ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
    cout << ans;
}