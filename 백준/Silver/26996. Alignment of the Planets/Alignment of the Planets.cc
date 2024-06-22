#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;
struct ans { int x, y, z; };

int main() {
	cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    vector<pii> v(n);
    for (auto &i : v) cin >> i.X >> i.Y;

    vector<ans> ansV;
    for (int x = 0; x < n-2; ++x) for (int y = x + 1; y < n-1; ++y) {
        int mt = (v[x].Y - v[y].Y), mb = (v[x].X - v[y].X);
        for (int z = y + 1; z < n; ++z) {
            int m2t = (v[x].Y - v[z].Y), m2b = (v[x].X - v[z].X);
            if (mt * m2b == mb * m2t) ansV.push_back({x+1, y+1, z+1});
        }
    }

    cout << ansV.size() << '\n';
    for (auto &x : ansV) cout << x.x << ' ' << x.y << ' ' << x.z << '\n';
}