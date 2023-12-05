#include<bits/stdc++.h>
#include <unordered_map>
#define RANGE(l, r) update(l+1, 1), update(r+2, -1);
#define FOR1(i, n) for (register int (i) = 1; (i) < (n) ; ++(i))
using namespace std;
 
constexpr int NODE_SIZE = 12000, DAY_SIZE = 1e6 + 1, STR_SIZE = 12;
 
int bit[DAY_SIZE + 1];
void update(int x, int val) {
    while (x <= DAY_SIZE) {
        bit[x] += val;
        x += (x & -x);
    }
}
char namePool[12001][STR_SIZE];
unordered_map<string, int> nameHash;
int nameCount;
int p[15][12001], lv[12001];
 
void init(char mAncestor[], int mDeathday) {
    memset(bit, 0, sizeof(bit));
    memset(p, 0, sizeof(p));
    nameHash.clear();
    nameCount = 0;
    strcpy(namePool[++nameCount], mAncestor);
    nameHash[namePool[nameCount]] = nameCount;
    lv[1] = 0;
    RANGE(0, mDeathday);
}
 
int add(char mName[], char mParent[], int mBirthday, int mDeathday) {
    register int cIdx, pIdx = nameHash[mParent];
    strcpy(namePool[++nameCount], mName);
    cIdx = nameHash[namePool[nameCount]] = nameCount;
 
    p[0][cIdx] = pIdx;
    FOR1(i, 14) p[i][cIdx] = p[i - 1][p[i - 1][cIdx]];
     
    RANGE(mBirthday, mDeathday);
    return lv[cIdx] = lv[pIdx] + 1;
}
 
int distance(char mName1[], char mName2[]) {
    register int aIdx = nameHash[mName1], bIdx = nameHash[mName2];
    int initLv = lv[aIdx] + lv[bIdx];
    if (lv[aIdx] < lv[bIdx]) swap(aIdx, bIdx);
     
    register int diff = lv[aIdx] - lv[bIdx];
    for (register int i = 0; diff > 0; ++i) {
        if (diff & 1) aIdx = p[i][aIdx];
        diff >>= 1;
    }
 
    for (register int i = 14; i >= 0; --i) {
        if (p[i][aIdx] == p[i][bIdx]) continue;
        aIdx = p[i][aIdx], bIdx = p[i][bIdx];
    }
    if (aIdx != bIdx) aIdx = p[0][aIdx];
 
    return initLv - 2 * lv[aIdx];
}
 
int count(int mDay) {
    register int x = mDay + 1, ret = 0;
    while (x > 0) {
        ret += bit[x];
        x -= (x & -x);
    } return ret;
}