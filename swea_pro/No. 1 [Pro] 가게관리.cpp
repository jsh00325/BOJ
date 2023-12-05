#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define MEM(x, y) memset((x), (y), sizeof(x))
#define FOR(i, n) for(register int (i) = 0; (i) < (n); ++(i))
 
struct BUY_INFO { int price, capacity, quantity, bID, pID; };
struct SELL_INFO { int price, quantity, pKey; bool isRefund; };
struct SELL_LOG { int bKey, quantity; };
 
constexpr int PRODUCT_SIZE = 600, BUY_SIZE = 30000, SELL_SIZE = 30000;
unordered_map<int, int> prod_um, buy_um, sell_um;
int stock[PRODUCT_SIZE], prod_cnt, buy_cnt, sell_cnt;
BUY_INFO buy_info[BUY_SIZE];
SELL_INFO sell_info[SELL_SIZE];
vector<SELL_LOG> sell_log[SELL_SIZE];
 
struct cmp {
    bool operator() (const int& a, const int& b) {
        const BUY_INFO& a_info = buy_info[a], & b_info = buy_info[b];
        if (a_info.price == b_info.price) return a_info.bID > b_info.bID;
        else return a_info.price > b_info.price;
    }
}; priority_queue<int, vector<int>, cmp> product_pq[PRODUCT_SIZE];
 
void init() {
    MEM(stock, 0); 
    prod_um.clear(), buy_um.clear(), sell_um.clear();
    FOR(i, prod_cnt) while (!product_pq[i].empty()) product_pq[i].pop();
    prod_cnt = buy_cnt = sell_cnt = 0;
}
 
int buy(int bId, int mProduct, int mPrice, int mQuantity) {
    if (prod_um.find(mProduct) == prod_um.end()) prod_um[mProduct] = prod_cnt++;
    buy_info[buy_um[bId] = buy_cnt] = { mPrice, mQuantity, mQuantity, bId, prod_um[mProduct] };
    stock[prod_um[mProduct]] += mQuantity;
    product_pq[prod_um[mProduct]].push(buy_cnt++);
    return stock[prod_um[mProduct]];
}
 
int cancel(int bId) {
    if (buy_um.find(bId) == buy_um.end()) return -1;
    BUY_INFO& info = buy_info[buy_um[bId]];
    if (info.quantity < info.capacity) return -1;
    stock[info.pID] -= info.quantity;
    info.quantity = 0;
    return stock[info.pID];
}
 
int sell(int sId, int mProduct, int mPrice, int mQuantity) {
    if (prod_um.find(mProduct) == prod_um.end()) return -1;
    int& prodKey = prod_um[mProduct];
 
    if (stock[prodKey] < mQuantity) return -1;
    SELL_INFO& info = sell_info[sell_um[sId] = sell_cnt++];
    info = { mPrice, mQuantity, prod_um[mProduct], false }, sell_log[sell_um[sId]].clear();
    stock[prodKey] -= mQuantity;
 
    int profit = 0;
    priority_queue<int, vector<int>, cmp>& pq = product_pq[prodKey];
    vector<SELL_LOG>& log = sell_log[sell_um[sId]];
    while (!pq.empty() && mQuantity > 0) {
        int cur_buyKey = pq.top(); pq.pop();
        BUY_INFO& buyInfo = buy_info[cur_buyKey];
        if (buyInfo.quantity == 0) continue;    // 환불된 bID 정보 -> pass
 
        if (buyInfo.quantity < mQuantity) {
            profit += (mPrice - buyInfo.price) * buyInfo.quantity;
            mQuantity -= buyInfo.quantity;
            log.push_back({cur_buyKey, buyInfo.quantity });
            buyInfo.quantity = 0;
        }
        else {
            profit += (mPrice - buyInfo.price) * mQuantity;
            buyInfo.quantity -= mQuantity;
            log.push_back({ cur_buyKey, mQuantity });
            mQuantity = 0;
 
            if (buyInfo.quantity) pq.push(cur_buyKey);          
        }
    }
    return profit;  
}
 
int refund(int sId) {
    if (sell_um.find(sId) == sell_um.end()) return -1;
    SELL_INFO& info = sell_info[sell_um[sId]];
    if (info.isRefund) return -1;
    priority_queue<int, vector<int>, cmp>& pq = product_pq[info.pKey];
    int& prod_stock = stock[info.pKey];
    for (SELL_LOG& log : sell_log[sell_um[sId]]) {
        buy_info[log.bKey].quantity += log.quantity;
        prod_stock += log.quantity;
        pq.push(log.bKey);
    }
    info.isRefund = true;
    return info.quantity;
}
