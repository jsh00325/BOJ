#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

const ll S1 = 56779, S2 = 97829, P1 = 993244853, P2 = 998244353, P3 = 1e9+7;
ll mpow1[100], mpow2[100];

ll get_hash(const char* str, int len, const ll& s, const ll& p) {
    ll ans = 0;
    FOR(i, len) ans = ((ans * s) + (str[i] - 'A')) % p;
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    mpow1[0] = mpow2[0] = 1;
    FOR(i, 99) {
        mpow1[i+1] = (mpow1[i] * S1) % P1;
        mpow2[i+1] = (mpow2[i] * S2) % P2;
    }
    
    int q; cin >> q;
    while (q--) {
        int n, m;
        char t[1000001], p[101];
        unordered_set<ll> vst;
        cin >> n >> m >> t >> p;

        ll h1 = get_hash(p, m, S1, P1), h2 = get_hash(p, m, S2, P2);
        vst.insert(h1 * P3 + h2);
        FOR(i, m - 1) for (int j = i + 2; j <= m; ++j) {
            reverse(p+i, p+j);
            h1 = get_hash(p, m, S1, P1), h2 = get_hash(p, m, S2, P2);
            vst.insert(h1 * P3 + h2);
            reverse(p+i, p+j);
        }
        
        int cnt = 0;
        h1 = get_hash(t, m, S1, P1), h2 = get_hash(t, m, S2, P2);
        FOR(i, n - m) {
            if (vst.count(h1 * P3 + h2)) cnt++;
            h1 = (h1 + P1 - ((t[i] - 'A') * mpow1[m-1]) % P1) % P1;
            h2 = (h2 + P2 - ((t[i] - 'A') * mpow2[m-1]) % P2) % P2;
            h1 = ((h1 * S1) + (t[i+m] - 'A')) % P1;
            h2 = ((h2 * S2) + (t[i+m] - 'A')) % P2;
        }
        if (vst.count(h1 * P3 + h2)) cnt++;
        cout << cnt << '\n';
    }
}