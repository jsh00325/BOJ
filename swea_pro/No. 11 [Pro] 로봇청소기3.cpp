#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (register int (i) = (0); (i) < (n); ++(i))
 
extern void scanFromRobot(int ceilingState[3][3]);
extern int moveRobot(int mCommand);
 
constexpr int di[4] = { -1, 0, 1, 0 }, dj[4] = { 0, -1, 0, 1 };
constexpr int moveDir[4][4] = { {0, 1, 2, 3}, {1, 2, 3, 0}, {2, 3, 0, 1}, {3, 0, 1, 2} }; // moveDir[현재방향][연산]
constexpr int findDir[4][4] = { {0, 1, 2, 3}, {3, 0, 1, 2}, {2, 3, 0, 1}, {1, 2, 3, 0} }; // findDir[현재방향][목표방향]
constexpr int revDir[4] = { 2, 3, 0, 1 };
 
int curDir;
bool visit[100][100];
 
void backTracking(int i, int j) {
    visit[i][j] = true;
 
    register int curStat[3][3] = { 0, };
    scanFromRobot(curStat);
 
    register int tempDir = curDir;
    FOR(cmd, 4) if (curStat[1 + di[cmd]][1 + dj[cmd]] == 0) {
        register int nxtDir = moveDir[tempDir][cmd];
        register int ni = i + di[nxtDir], nj = j + dj[nxtDir];
        if (visit[ni][nj]) continue;
 
        moveRobot(findDir[curDir][nxtDir]);
        curDir = nxtDir;
 
        backTracking(ni, nj);
 
        moveRobot(findDir[curDir][revDir[nxtDir]]);
        curDir = revDir[nxtDir];
    }
}
 
void init(int N, int subTaskCount) {  }
void cleanHouse(int mLimitMoveCount) {
    memset(visit, false, sizeof(visit));
    backTracking(50, 50);
}