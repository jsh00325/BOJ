#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int,int> cnt;
bool cmp(const int &a, const int &b) {
    return cnt[a] > cnt[b];
}

int solution(int k, vector<int> tangerine) {
    vector<int> v;
    for (int t : tangerine)
        if (cnt.find(t) != cnt.end()) cnt[t]++;
        else {
            cnt[t] = 1;
            v.push_back(t);
        }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        k -= cnt[v[i]];
        if (k <= 0) return i + 1;
    }
    return v.size();
}