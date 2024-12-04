#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 3, NONE = -1;
struct node {
    int prv, nxt;
} dll[MX];
bool isLIS[MX];

void initDLL(int n);
void moveToFrontOf(int x, int y);
void moveToBackOf(int x, int y);
int findDLLHeadIndex(int n);
vector<int> extractVector(int head);
int findLIS(vector<int> &v);

// O(N + M)
vector<int> step1(int n, int m) {
    initDLL(n);

    while (m--) {
        char op; int x, y; cin >> op >> x >> y;
        if (op == 'A') moveToFrontOf(x, y);
        else moveToBackOf(x, y);
    }
    
    int headIndex = findDLLHeadIndex(n);
    return extractVector(headIndex);
}

// O(NlgN)
void step2(int n, vector<int> &v) {
    int lisLength = findLIS(v);
    cout << n - lisLength << '\n';

    queue<int> q;
    for (int i = 1; i <= n; ++i) if (isLIS[i]) q.push(i);
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur - 1 >= 1 && !isLIS[cur-1]) {
            cout << "A " << cur-1 << ' ' << cur << '\n';
            q.push(cur-1); isLIS[cur-1] = 1;
        }
        if (cur + 1 <= n && !isLIS[cur+1]) {
            cout << "B " << cur+1 << ' ' << cur << '\n';
            q.push(cur+1); isLIS[cur+1] = 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> v = step1(n, m);
    step2(n, v);
}

// O(N)
void initDLL(int n) {
    for (int i = 1; i <= n; ++i) {
        dll[i].prv = (i == 1 ? NONE : i - 1);
        dll[i].nxt = (i == n ? NONE : i + 1);
    }
}

// O(1)
void moveToFrontOf(int x, int y) {
    node &xNode = dll[x], &yNode = dll[y];

    if (xNode.prv != NONE) dll[xNode.prv].nxt = xNode.nxt;
    if (xNode.nxt != NONE) dll[xNode.nxt].prv = xNode.prv;

    xNode.prv = yNode.prv;
    xNode.nxt = y;

    if (yNode.prv != NONE) dll[yNode.prv].nxt = x;
    yNode.prv = x;
}

// O(1)
void moveToBackOf(int x, int y) {
    node &xNode = dll[x], &yNode = dll[y];

    if (xNode.prv != NONE) dll[xNode.prv].nxt = xNode.nxt;
    if (xNode.nxt != NONE) dll[xNode.nxt].prv = xNode.prv;

    xNode.prv = y;
    xNode.nxt = yNode.nxt;

    if (yNode.nxt != NONE) dll[yNode.nxt].prv = x;
    yNode.nxt = x;
}

// O(N)
int findDLLHeadIndex(int n) {
    for (int i = 1; i <= n; ++i) {
        if (dll[i].prv == NONE) return i;
    }
}

// O(N)
vector<int> extractVector(int head) {
    vector<int> result;

    int cur = head;
    while (cur != NONE) {
        result.push_back(cur);
        cur = dll[cur].nxt;
    }

    return result;
}

// O(NlgN)
int findLIS(vector<int> &v) {
    int n = v.size();
    vector<int> lis = { v[0] }, lisIndex(n);
    lisIndex[0] = 1;

    for (int i = 1; i < n; ++i) {
        if (lis.end()[-1] < v[i]) {
            lis.push_back(v[i]);
            lisIndex[i] = lis.size();
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
            lisIndex[i] = idx + 1;
        }
    }

    int target = lis.size();
    for (int i = n-1; i >= 0; --i) {
        if (lisIndex[i] == target) isLIS[v[i]] = 1, --target;
    }

    return lis.size();
}