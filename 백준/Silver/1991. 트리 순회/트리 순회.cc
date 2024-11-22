#include <bits/stdc++.h>
using namespace std;

int n, lc[30], rc[30];

string preorder(int cur) {
    string ret = "";
    ret += cur + 'A';
    if (lc[cur] != -1) ret += preorder(lc[cur]);
    if (rc[cur] != -1) ret += preorder(rc[cur]);
    return ret;
}

string inorder(int cur) {
    string ret = "";
    if (lc[cur] != -1) ret += inorder(lc[cur]);
    ret += cur + 'A';
    if (rc[cur] != -1) ret += inorder(rc[cur]);
    return ret;
}

string postorder(int cur) {
    string ret = "";
    if (lc[cur] != -1) ret += postorder(lc[cur]);
    if (rc[cur] != -1) ret += postorder(rc[cur]);
    ret += cur + 'A';
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        char p, l, r; cin >> p >> l >> r;
        lc[p - 'A'] = (l == '.' ? -1 : l - 'A');
        rc[p - 'A'] = (r == '.' ? -1 : r - 'A');
    }
    cout << preorder(0) << '\n' << inorder(0) << '\n' << postorder(0);
}