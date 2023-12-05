#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (register int (i) = 0; (i) < (n); ++(i))
 
// 비용 우선순위 큐
struct priceNode { int dist, airport; };
struct PriceMinHeap {
    priceNode arr[10000]; int size = 0;
 
    void push(const int& dist, const int& airport) {
        arr[++size] = { dist, airport };
        register int cur = size, p = cur >> 1;
        while (cur != 1) {
            if (arr[p].dist <= arr[cur].dist) break;
            swap(arr[p], arr[cur]);
            cur = p, p = cur >> 1;
        }
    }
    void pop(int& cur_dist, int& cur_airport) {
        cur_dist = arr[1].dist, cur_airport = arr[1].airport;
        arr[1] = arr[size--];
        register int cur = 1, l = cur << 1, r = l | 1, mn = l;
        while (l <= size) {
            if (r <= size && arr[l].dist > arr[r].dist) mn = r;
            if (arr[cur].dist <= arr[mn].dist) break;
            swap(arr[cur], arr[mn]);
            cur = mn, l = cur << 1, r = l | 1, mn = l;
        }
    }
    void clear() { size = 0; }
}; PriceMinHeap pricePQ;
 
// 시간 우선순위 큐
struct timeNode { int alltime, airport, time; };
struct TimeMinHeap {
    timeNode arr[1<<15]; int size = 0;
 
    void push(const int& alltime, const int& airport, const int& time) {
        arr[++size] = { alltime, airport, time };
        register int cur = size, p = cur >> 1;
        while (cur != 1) {
            if (arr[p].alltime <= arr[cur].alltime) break;
            swap(arr[p], arr[cur]);
            cur = p, p = cur >> 1;
        }
    }
    void pop(int& cur_alltime, int& cur_airport, int& cur_time) {
        cur_alltime = arr[1].alltime, cur_airport = arr[1].airport, cur_time = arr[1].time;
        arr[1] = arr[size--];
        register int cur = 1, l = cur << 1, r = l | 1, mn = l;
        while (l <= size) {
            if (r <= size && arr[l].alltime > arr[r].alltime) mn = r;
            if (arr[cur].alltime <= arr[mn].alltime) break;
            swap(arr[cur], arr[mn]);
            cur = mn, l = cur << 1, r = l | 1, mn = l;
        }
    }
    void clear() { size = 0; }
}; TimeMinHeap timePQ;
 
 
constexpr int AIRPORT_SIZE = 60, TIME_SIZE = 24, INF = 0x7fffffff;
 
// 비용 간선 인접행렬
int n, priceEdge[AIRPORT_SIZE][AIRPORT_SIZE];
 
// 시간 간선 인접리스트
struct TimeEdge { int airport, time, travel; };
vector<TimeEdge> timeEdge[AIRPORT_SIZE][TIME_SIZE];
 
void init(int N) {
    n = N;
    FOR(i, N) FOR(j, N) priceEdge[i][j] = INF;
    FOR(i, N) FOR(j, TIME_SIZE) timeEdge[i][j].clear();
}
 
void add(int mStartAirport, int mEndAirport, int mStartTime, int mTravelTime, int mPrice) {
    // 시간 간선 추가
    timeEdge[mStartAirport][mStartTime].push_back({ mEndAirport, (mStartTime + mTravelTime) % TIME_SIZE, mTravelTime });
    // 비용 업데이트
    if (priceEdge[mStartAirport][mEndAirport] > mPrice) priceEdge[mStartAirport][mEndAirport] = mPrice;
}
 
int minTravelTime(int mStartAirport, int mEndAirport, int mStartTime) {
    register int d[AIRPORT_SIZE][TIME_SIZE]; FOR(i, n) FOR(j, TIME_SIZE) d[i][j] = INF;
    timePQ.clear(); d[mStartAirport][mStartTime] = 0; timePQ.push(0, mStartAirport, mStartTime);
    while (timePQ.size) {
        register int cur_alltime, cur_airport, cur_time;
        timePQ.pop(cur_alltime, cur_airport, cur_time);
 
        if (cur_airport == mEndAirport) return cur_alltime;
        if (d[cur_airport][cur_time] < cur_alltime) continue;
        for (TimeEdge& nxt : timeEdge[cur_airport][cur_time]) {
            if (d[nxt.airport][nxt.time] > cur_alltime + nxt.travel) {
                d[nxt.airport][nxt.time] = cur_alltime + nxt.travel;
                timePQ.push(d[nxt.airport][nxt.time], nxt.airport, nxt.time);
            }
        }
        register int nxtTime = (cur_time == 23 ? 0 : cur_time + 1);
        if (d[cur_airport][nxtTime] > cur_alltime + 1) {
            d[cur_airport][nxtTime] = cur_alltime + 1;
            timePQ.push(d[cur_airport][nxtTime], cur_airport, nxtTime);
        }
    } return -1;
}
 
int minPrice(int mStartAirport, int mEndAirport) {
    register int d[AIRPORT_SIZE]; FOR(i, n) d[i] = INF;
    pricePQ.clear(); d[mStartAirport] = 0; pricePQ.push(0, mStartAirport);
    while (pricePQ.size) {
        register int cur_dist, cur_airport;
        pricePQ.pop(cur_dist, cur_airport);
        if (cur_airport == mEndAirport) return cur_dist;
        if (cur_dist > d[cur_airport]) continue;
        FOR(nxt, n) if (priceEdge[cur_airport][nxt] != INF) {
            if (d[nxt] > cur_dist + priceEdge[cur_airport][nxt]) {
                d[nxt] = cur_dist + priceEdge[cur_airport][nxt];
                pricePQ.push(d[nxt], nxt);
            }
        }
    } return -1;
}