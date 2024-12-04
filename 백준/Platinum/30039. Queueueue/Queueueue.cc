#include <bits/stdc++.h>
using namespace std;

const int MX = 2e6+3, NONE = -1;
struct node {
    int vprv, vnxt, hprv, hnxt, value;
} arr[MX];

int vfr = NONE, vbk = NONE, hfr = NONE, hbk = NONE, mid = NONE;
int nodecnt, qqsize, hsize, vsize;

void hpush(int x) {
    int curIdx = nodecnt++;
    node &cur = arr[curIdx];

    cur.value = x;
    if (hbk != NONE) arr[hbk].hnxt = curIdx;
    cur.hprv = hbk, cur.hnxt = NONE;
    cur.vprv = NONE, cur.vnxt = NONE;

    if (hfr == NONE) hfr = curIdx;
    hbk = curIdx;

    ++qqsize, ++hsize;
    
    // 이번 삽입으로 처음 원소가 생긴 경우
    if (qqsize == 1) {
        vsize = 1;
        vfr = vbk = mid = curIdx;
    }
    // mid가 변경되어야 하는 경우
    else if (hsize & 1) {
        int nmid = arr[mid].hnxt;
        if (arr[mid].vprv != NONE) arr[arr[mid].vprv].vnxt = nmid;
        if (arr[mid].vnxt != NONE) arr[arr[mid].vnxt].vprv = nmid;
        arr[nmid].vprv = arr[mid].vprv;
        arr[nmid].vnxt = arr[mid].vnxt;
        arr[mid].vprv = arr[mid].vnxt = NONE;
        mid = nmid;

        // vfr, vbk도 변경되어야 하는 경우
        if (vsize == 1) {
            vfr = vbk = mid;
        } else if (vsize == 2) {
            vfr = mid;
        }
    }
}
int hpop() {
    if (hfr == NONE) return -1;

    node &cur = arr[hfr];
    int result = cur.value;

    --qqsize;

    // 완전 구조 변경 필요
    if (hsize == 1) {
        if (cur.vprv != NONE) arr[cur.vprv].vnxt = cur.vnxt;
        if (cur.vnxt != NONE) arr[cur.vnxt].vprv = cur.vprv;
        
        --vsize;
        int nmid;
        if (vsize & 1) nmid = arr[mid].vnxt;
        else nmid = arr[mid].vprv;

        hfr = hbk = mid = nmid;
        if (vsize == 1) vfr = vbk = nmid;
        else if (vsize == 2) vfr = nmid;
    }
    // 일단 삭제하자..
    else {
        arr[cur.hnxt].hprv = NONE;
        hfr = cur.hnxt;
        --hsize;

        // mid가 변경되어야 하는 경우
        if (hsize & 1) {
            int nmid = arr[mid].hnxt;
            if (arr[mid].vprv != NONE) arr[arr[mid].vprv].vnxt = nmid;
            if (arr[mid].vnxt != NONE) arr[arr[mid].vnxt].vprv = nmid;
            arr[nmid].vprv = arr[mid].vprv;
            arr[nmid].vnxt = arr[mid].vnxt;
            arr[mid].vprv = arr[mid].vnxt = NONE;
            mid = nmid;

            if (vsize == 1) vfr = vbk = mid;
            else if (vsize == 2) vfr = mid;
        }
    }

    if (qqsize == 0) {
        vfr = vbk = hfr = hbk = mid = NONE;
        qqsize = hsize = vsize = 0;
    }

    return result;
}
void vpush(int x) {
    int curIdx = nodecnt++;
    node &cur = arr[curIdx];

    cur.value = x;
    cur.hprv = NONE, cur.hnxt = NONE;
    if (vbk != NONE) arr[vbk].vnxt = curIdx;
    cur.vprv = vbk, cur.vnxt = NONE;

    if (vfr == NONE) vfr = curIdx;
    vbk = curIdx;

    ++qqsize, ++vsize;
    
    // 이번 삽입으로 처음 원소가 생긴 경우
    if (qqsize == 1) {
        hsize = 1;
        hfr = hbk = mid = curIdx;
    }
    // mid가 변경되어야 하는 경우
    else if (vsize & 1) {
        int nmid = arr[mid].vnxt;
        if (arr[mid].hprv != NONE) arr[arr[mid].hprv].hnxt = nmid;
        if (arr[mid].hnxt != NONE) arr[arr[mid].hnxt].hprv = nmid;
        arr[nmid].hprv = arr[mid].hprv;
        arr[nmid].hnxt = arr[mid].hnxt;
        arr[mid].hprv = arr[mid].hnxt = NONE;
        mid = nmid;

        // hfr, hbk도 변경되어야 하는 경우
        if (hsize == 1) {
            hfr = hbk = mid;
        } else if (hsize == 2) {
            hfr = mid;
        }
    }
}
int vpop() {
    if (vfr == NONE) return -1;

    node &cur = arr[vfr];
    int result = cur.value;

    --qqsize;

    // 완전 구조 변경 필요
    if (vsize == 1) {
        if (cur.hprv != NONE) arr[cur.hprv].hnxt = cur.hnxt;
        if (cur.hnxt != NONE) arr[cur.hnxt].hprv = cur.hprv;
        
        --hsize;
        int nmid;
        if (hsize & 1) nmid = arr[mid].hnxt;
        else nmid = arr[mid].hprv;

        vfr = vbk = mid = nmid;
        if (hsize == 1) hfr = hbk = nmid;
        else if (hsize == 2) hfr = nmid;
    }
    // 일단 삭제하자..
    else {
        arr[cur.vnxt].vprv = NONE;
        vfr = cur.vnxt;
        --vsize;

        // mid가 변경되어야 하는 경우
        if (vsize & 1) {
            int nmid = arr[mid].vnxt;
            if (arr[mid].hprv != NONE) arr[arr[mid].hprv].hnxt = nmid;
            if (arr[mid].hnxt != NONE) arr[arr[mid].hnxt].hprv = nmid;
            arr[nmid].hprv = arr[mid].hprv;
            arr[nmid].hnxt = arr[mid].hnxt;
            arr[mid].hprv = arr[mid].hnxt = NONE;
            mid = nmid;

            if (hsize == 1) hfr = hbk = mid;
            else if (hsize == 2) hfr = mid;
        }
    }

    if (qqsize == 0) {
        vfr = vbk = hfr = hbk = mid = NONE;
        qqsize = hsize = vsize = 0;
    }

    return result;

}
int getValue(int idx) {
    if (idx == NONE) return -1;
    else return arr[idx].value;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    while (n--) {
        string op; cin >> op;
        if (op == "hpush") {
            int x; cin >> x;
            hpush(x);            
        } else if (op == "hpop") {
            cout << hpop() << '\n';
        } else if (op == "hfront") {
            cout << getValue(hfr) << '\n';
        } else if (op == "hback") {
            cout << getValue(hbk) << '\n';
        } else if (op == "hsize") {
            cout << hsize << '\n';
        } else if (op == "vpush") {
            int x; cin >> x;
            vpush(x);
        } else if (op == "vpop") {
            cout << vpop() << '\n';
        } else if (op == "vfront") {
            cout << getValue(vfr) << '\n';
        } else if (op == "vback") {
            cout << getValue(vbk) << '\n';
        } else if (op == "vsize") {
            cout << vsize << '\n';           
        } else if (op == "size") {
            cout << qqsize << '\n';            
        } else if (op == "empty") {
            cout << (qqsize == 0) << '\n';
        } else if (op == "middle") {
            cout << getValue(mid) << '\n';
        }
    }
}