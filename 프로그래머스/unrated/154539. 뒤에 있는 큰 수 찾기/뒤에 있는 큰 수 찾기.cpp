#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

vector<int> solution(vector<int> nums) {
    vector<int> ans(nums.size(), -1);
    stack<pii> s;
    for (int i = 0; i < nums.size(); i++) {
        while (!s.empty() && s.top().Y < nums[i]) {
            ans[s.top().X] = nums[i];
            s.pop();
        }
        s.push({i, nums[i]});
    }
    
    return ans;
}