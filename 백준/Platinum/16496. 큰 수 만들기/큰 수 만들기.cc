#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

bool cmp(const string& a, const string& b) {
    if (a.size() == b.size()) return stoi(a) > stoi(b);
    else if (a.size() < b.size()) {
        FOR(i, a.size()) if (a[i] != b[i]) return a[i] > b[i];
        return cmp(a, b.substr(a.size(), b.size() - a.size()));
    }
    else {
        FOR(i, b.size()) if (a[i] != b[i]) return a[i] > b[i];
        return cmp(a.substr(b.size(), a.size() - b.size()), b);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    int n; cin >> n; string arr[1000];
    FOR(i, n) cin >> arr[i];
    sort(arr, arr + n, cmp);
    if (arr[0][0] == '0') cout << 0;
    else FOR(i, n) cout << arr[i];
}