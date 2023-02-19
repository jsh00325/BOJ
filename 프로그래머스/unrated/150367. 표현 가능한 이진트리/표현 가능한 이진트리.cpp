#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

ll exp[6] = {1, 3, 7, 15, 31, 63};
ll arr[6] = {1, 1, 1, 1, 1, (ll)1e18}; // {2^1, 2^3, 2^7, 2^15, 2^31, 2^63}

ll get_len(ll x) {
    for (int i = 0; i < 6; i++) if (x < arr[i]) return exp[i];
}
bool n_solve(ll x, ll len) {
    if (len == 1 || x == 0) return true;
    ll mid = len / 2;
    if (!n_solve(x % ((ll)1 << mid), mid)) return false;
    x = x >> mid;
    if ((x % 2) == 0) return false;
    x /= 2;
    return n_solve(x, mid);
}
int get_len_idx(ll x) { for (int i = 0; i < 6; i++) if (x < arr[i]) return i; }
bool solve(ll x, int lidx) {
    if (!lidx || !x) return true;
    lidx--;
    if (!solve(x % arr[lidx], lidx)) return false;
    x >>= exp[lidx];
    if (!(x & 1)) return false;
    return solve(x >> 1, lidx);
}

vector<int> solution(vector<ll> nums) { 
    for (int i = 0; i < 5; i++) arr[i] = arr[i] << exp[i];
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++) if (solve(nums[i], get_len_idx(nums[i]))) ans[i] = 1;
    return ans;
}