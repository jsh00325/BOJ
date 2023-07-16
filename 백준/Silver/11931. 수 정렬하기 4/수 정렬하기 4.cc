#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

int n, arr[1000000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    FOR(i, n) cin >> arr[i];
    sort(arr, arr+n, [](const int& a, const int& b){return a > b;});
    FOR(i, n) cout << arr[i] << '\n';
}