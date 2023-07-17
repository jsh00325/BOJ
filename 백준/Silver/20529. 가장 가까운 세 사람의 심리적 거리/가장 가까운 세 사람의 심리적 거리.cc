#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++i)

int t, n, cnt[16], lst[32];
string s;
unordered_map<string, int> um;

void setDist2(int& ans, const int& a, const int& b) {
    FOR(i, 4) ans += (((a >> i) & 1) != ((b >> i) & 1));
}
int getDist3(const int& a, const int& b, const int& c) {
    int ans = 0;
    setDist2(ans, a, b), setDist2(ans, a, c), setDist2(ans, b, c);
    return ans;
}

int solve() {
    cin >> n; MEM(cnt, 0);
    FOR(i, n) cin >> s, cnt[um[s]]++;
    if (n > 32) return 0;
    int idx = 0, ans = 99;
    FOR(i, 16) FOR(k, cnt[i]) lst[idx++] = i;
    
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            for (int k = j + 1; k < n; k++) {
                int cur = getDist3(lst[i], lst[j], lst[k]);
                if (ans > cur) ans = cur;
            }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    um["ISTJ"] = 0b1000, um["ISFJ"] = 0b1010, um["INFJ"] = 0b1110, um["INTJ"] = 0b1100;
    um["ISTP"] = 0b1001, um["ISFP"] = 0b1011, um["INFP"] = 0b1111, um["INTP"] = 0b1101;
    um["ESTP"] = 0b0001, um["ESFP"] = 0b0011, um["ENFP"] = 0b0111, um["ENTP"] = 0b0101;
    um["ESTJ"] = 0b0000, um["ESFJ"] = 0b0010, um["ENFJ"] = 0b0110, um["ENTJ"] = 0b0100;
    
    cin >> t;
    FOR(i, t) cout << solve() << '\n';
}