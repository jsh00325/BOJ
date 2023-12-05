#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define FOR(i, n) for(register int (i) = 0; (i) < (n); ++(i))
typedef long long ll;
 
constexpr int LAND_SIZE = 625, COLOR_SIZE = 625;
constexpr int di[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dj[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
// 군주 이름을 압축해서 um -> 군주의 위치
unordered_map<ll, int> monarch_um;
ll compression(const char* str) {
    ll rslt = 0; char c;
    while (c = *(str++)) rslt = (rslt << 5) | (c ^ 96);
    return rslt;
}
 
// 군주의 넘버링과 병사 수 기록
struct LAND { int soldier, color; };
int n; LAND land[LAND_SIZE];
 
// 2차원 -> 1차원 인덱스
inline int convert(int i, int j) { return i * n + j; }
 
// 적대관계 기록용 (color와 color 사이)
bool isNeg[COLOR_SIZE][COLOR_SIZE];
 
////////////////////////////////////////////////////////////////////////////////////////////////
 
void init(int N, int mSoldier[25][25], char mMonarch[25][25][11]) {
    n = N;
    FOR(i, N) FOR(j, N) {
        ll curID = compression(mMonarch[i][j]);
        land[convert(i, j)] = { mSoldier[i][j], convert(i, j) };
        monarch_um[curID] = convert(i, j);
    }
}
 
void destroy() {
    monarch_um.clear();
    FOR(i, COLOR_SIZE) FOR(j, COLOR_SIZE) isNeg[i][j] = false;
}
 
int ally(char mMonarchA[11], char mMonarchB[11]) {
    int& aIdx = monarch_um[compression(mMonarchA)], & bIdx = monarch_um[compression(mMonarchB)];
    LAND& aland = land[aIdx], & bland = land[bIdx];
     
    if (aland.color == bland.color) return -1;
    if (isNeg[aland.color][bland.color]) return -2;
 
    register int tempBcolor = bland.color;
    FOR(i, n * n) if (land[i].color == tempBcolor) land[i].color = aland.color;
    FOR(i, n * n) if (isNeg[tempBcolor][i]) isNeg[aland.color][i] = isNeg[i][aland.color] = true;
 
    return 1;
}
 
int isAttackable(int idx, int target) {
    register int i = idx / n, j = idx % n;
    FOR(dir, 8) {
        register int ni = i + di[dir], nj = j + dj[dir];
        if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
        if (land[convert(ni, nj)].color == target) return true;
    } return false;
}
int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11]) {
    int& aIdx = monarch_um[compression(mMonarchA)], & bIdx = monarch_um[compression(mMonarchB)];
    LAND& aland = land[aIdx], & bland = land[bIdx];
 
    if (aland.color == bland.color) return -1;
    if (!isAttackable(bIdx, aland.color)) return -2;
 
    isNeg[aland.color][bland.color] = isNeg[bland.color][aland.color] = true;
    register int i = bIdx / n, j = bIdx % n, attack = 0;
    FOR(dir, 8) {
        register int ni = i + di[dir], nj = j + dj[dir];
        if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
        LAND &nxt_land = land[convert(ni, nj)];
        if (nxt_land.color == aland.color) {
            register int moved = (nxt_land.soldier / 2);
            nxt_land.soldier -= moved; attack += moved;
        }
        else if (nxt_land.color == bland.color) {
            register int moved = (nxt_land.soldier / 2);
            nxt_land.soldier -= moved; bland.soldier += moved;
        }
    }
 
    if (attack > bland.soldier) {
        monarch_um[compression(mGeneral)] = bIdx;
        bland.color = aland.color;
        bland.soldier = attack - bland.soldier;
        return 1;
    }
    else {
        bland.soldier -= attack;
        return 0;
    }
}
 
int recruit(char mMonarch[11], int mNum, int mOption)
{
    int& curIdx = monarch_um[compression(mMonarch)];
    if (mOption == 0) return (land[curIdx].soldier += mNum);
 
    int ans = 0;
    FOR(i, n*n) if (land[i].color == land[curIdx].color)
        ans += (land[i].soldier += mNum);
    return ans;
}