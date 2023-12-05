#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
#define FOR1(i, n) for (register int (i) = 1; (i) <= (n); ++(i))
 
constexpr int TIME_SIZE = 86400;
int modifyTime[TIME_SIZE+1], rsltTime[TIME_SIZE+1];
 
struct Employee {
    int start, end;
    bool valid;
} employee_pool[8000];
int employeePoolCount, employeeCount;
 
unordered_map<int, Employee*> employeeHash;
 
 
void init() {
    employeeHash.clear();
    employeePoolCount = employeeCount = 0;
}
 
int add(int mId, int mStart, int mEnd) {
    if (employeeHash.find(mId) == employeeHash.end()) {
        Employee& curEmp = employee_pool[employeePoolCount++];
        curEmp = { mStart, mEnd, true };
        employeeHash[mId]= &curEmp;
        return ++employeeCount;
    }
    else {
        Employee* curEmp = employeeHash[mId];
        curEmp->start = mStart, curEmp->end = mEnd;
        if (curEmp->valid) return employeeCount;
        curEmp->valid = true;
        return ++employeeCount;
    }
}
 
int remove(int mId) {
    Employee* curEmp = employeeHash[mId];
    if (!curEmp->valid) return employeeCount;
    curEmp->valid = false;
    return --employeeCount;
}
 
int announce(int mDuration, int M) {
    memset(modifyTime, 0, sizeof(modifyTime));
    for (auto it = employeeHash.begin(); it != employeeHash.end(); ++it) {
        Employee* curEmployee = (*it).second;
        if (!curEmployee->valid) continue;
        if (curEmployee->end - curEmployee->start + 1 < mDuration) continue;
        ++modifyTime[curEmployee->start];
        --modifyTime[curEmployee->end - mDuration + 2];
    }
 
    register int cur = modifyTime[0];
    if (cur >= M) return 0;
    FOR1(i, TIME_SIZE) {
        cur += modifyTime[i];
        if (cur >= M) return i;
    }
    return -1;
}