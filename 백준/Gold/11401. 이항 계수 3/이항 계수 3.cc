#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); ++i)

const ll MOD = 1e9 + 7, MX = 4000000;
ll n, k, fact[MX + 1] = {1, }, ans;

ll mpow(ll a, ll b) {
    ll ans = 1, base = a;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        b /= 2;
    } return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    FOR1(i, MX) fact[i] = (fact[i-1] * i) % MOD;
    cin >> n >> k;
    cout << (fact[n] * mpow((fact[k] * fact[n-k]) % MOD, MOD-2)) % MOD;
}