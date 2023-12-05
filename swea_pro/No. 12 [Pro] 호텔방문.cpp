#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (register int (i) = 0; (i) < (n); ++(i))
 
constexpr int CITY_SIZE = 5000, INF = 0x3fffffff;
int n, brand[CITY_SIZE];
 
struct Edge { int dist, w; };
vector<Edge> edge[CITY_SIZE];
 
void init(int N, int mBrands[]) {
    n = N;
    FOR(i, N) {
        brand[i] = mBrands[i];
        edge[i].clear();
    }
}
 
void connect(int mHotelA, int mHotelB, int mDistance) {
    edge[mHotelA].push_back({ mHotelB, mDistance });
    edge[mHotelB].push_back({ mHotelA, mDistance });
}
 
int merge(int mHotelA, int mHotelB) {
    register int ans = 0, brandA = brand[mHotelA], brandB = brand[mHotelB];
    FOR(i, n) {
        if (brand[i] == brandA) ++ans;
        else if (brand[i] == brandB) brand[i] = brandA, ++ans;
    }
    return ans;
}
 
struct Heap {
    struct Node { int dist, node; } arr[15000];
    int size;
 
    void init() { size = 0; }
    void push(int d, int n) {
        arr[++size] = { d, n };
        register int cur = size, p = cur >> 1;
        while (cur > 1) {
            if (arr[p].dist <= arr[cur].dist) break;
            swap(arr[p], arr[cur]);
            cur = p, p = cur >> 1;
        }
    }
    void pop(int& d, int& n) {
        d = arr[1].dist, n = arr[1].node;
        arr[1] = arr[size--];
        register int cur = 1, l = cur << 1, r = l | 1, ch = l;
        while (l <= size) {
            if (r <= size && arr[r].dist < arr[l].dist) ch = r;
            if (arr[cur].dist <= arr[ch].dist) break;
            swap(arr[cur], arr[ch]);
            cur = ch, l = cur << 1, r = l | 1, ch = l;
        }
    }
} pq;
 
unsigned int d[CITY_SIZE];
int move(int mStart, int mBrandA, int mBrandB) {
    memset(d, -1, sizeof(d)); pq.init();
    d[mStart] = 0; pq.push(0, mStart);
 
    register bool Avisit = false, Bvisit = false;
    register int ans = 0;
     
    while (pq.size) {
        register int curDist, curNode; pq.pop(curDist, curNode);
        if (d[curNode] < curDist) continue;
 
        if (curNode != mStart) {
            if (!Avisit && brand[curNode] == mBrandA) ans += curDist, Avisit = true;
            else if (!Bvisit && brand[curNode] == mBrandB) ans += curDist, Bvisit = true;
            if (Avisit && Bvisit) return ans;
        }
 
        for (Edge& nxt : edge[curNode]) {
            if (d[nxt.dist] > curDist + nxt.w) {
                d[nxt.dist] = curDist + nxt.w;
                pq.push(d[nxt.dist], nxt.dist);
            }
        }
    }
}