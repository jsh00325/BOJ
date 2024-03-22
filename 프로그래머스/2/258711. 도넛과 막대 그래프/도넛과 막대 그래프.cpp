#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6;
vector<int> edge[MX+1];
int ind[MX+1], outd[MX+1];
bool vst[MX+1], isExist[MX+1];

void visit(int st) {
    vst[st] = true;
    if (!outd[st]) return;
    if (vst[edge[st][0]]) return;
    visit(edge[st][0]);
}

vector<int> solution(vector<vector<int>> edges_info) {
    vector<int> ans(4);
    
    for (auto& edge_info : edges_info) {
        edge[edge_info[0]].push_back(edge_info[1]);
        ++ind[edge_info[1]]; ++outd[edge_info[0]];
        isExist[edge_info[0]] = isExist[edge_info[1]] = true;
    }
    
    for (int i = 1; i <= MX; ++i) if (isExist[i]) {
        if (ind[i] == 0 && outd[i] >= 2) {
            ans[0] = i;
            vst[i] = true;
            for (auto& nxt : edge[i]) --ind[nxt];
            break;
        }
    }
    
    for (int i = 1; i <= MX; ++i) if (isExist[i]) if (!vst[i]) {        
        if (ind[i] == 2 && outd[i] == 2) {
            // 해당 정점은 8자의 중심을 이루는 정점
            vst[i] = true;
            visit(edge[i][0]);
            visit(edge[i][1]);
            ++ans[3];
        }
        else if (ind[i] == 0) {
            // 해당 정점은 막대의 시작 위치
            visit(i);
            ++ans[2];   
        }
    }
    
    // 도넛 검출
    for (int i = 1; i <= MX; ++i) if (isExist[i]) if (!vst[i]) {
        visit(i);
        ++ans[1];
    }
    
    assert(outd[ans[0]] == (ans[1] + ans[2] + ans[3]));
    
    return ans;
}