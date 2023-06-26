#include <bits/stdc++.h>
using namespace std;

bool vst[10];

int solution(vector<int> nums) {
    for (int x : nums) vst[x] = true;
    int ans = 0;
    for (int i = 0; i < 10; i++) ans += (vst[i] ? 0 : i);
    return ans;
}