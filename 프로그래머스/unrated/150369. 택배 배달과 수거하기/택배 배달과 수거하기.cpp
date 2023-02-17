#include <string>
#include <vector>
using namespace std;

long long solution(int cap, int n, vector<int> deli, vector<int> pic) {
    long long ans = 0;
    
    int last_idx = n - 1;
    for (last_idx; last_idx >= 0; last_idx--)
        if (deli[last_idx] || pic[last_idx]) break;
    
    while (last_idx >= 0) {
        int d = cap, p = cap;
        
        for (int i = last_idx; i >= 0; i--) {
            if (deli[i] <= d) { d -= deli[i]; deli[i] = 0; }
            else { deli[i] -= d; d = 0; }
            
            if (!d) break;
        }
        
        for (int i = last_idx; i >= 0; i--) {
            if (pic[i] <= p) { p -= pic[i]; pic[i] = 0; }
            else { pic[i] -= p; p = 0; }
            
            if (!p) break;
        }
        
        ans += last_idx * 2 + 2;
        for (last_idx; last_idx >= 0; last_idx--)
            if (deli[last_idx] || pic[last_idx]) break;
    }
    return ans;
}