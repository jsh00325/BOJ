#include<bits/stdc++.h>
using namespace std;

// preorder에서 [st, en)범위를 postorder로 바꾸어 출력하는 함수
void postorder(vector<int> &preorder, int st, int en) {
    if (st >= en) return;

    for (int r = st + 1; r < en; ++r) {
        if (preorder[st] < preorder[r]) {
            postorder(preorder, st + 1, r);
            postorder(preorder, r, en);
            cout << preorder[st] << '\n';
            return;
        }
    }

    postorder(preorder, st+1, en);
    cout << preorder[st] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<int> preorder; int cur;
    while (cin >> cur) preorder.push_back(cur);

    postorder(preorder, 0, preorder.size());
}