#include <bits/stdc++.h>
using namespace std;

struct node {
	char lab;
	int x, y;
};

const char NONE = '#';
char arr[30][30];

bool check_rect(int l, int r, int d, int u) {
	if (arr[l][d] == NONE || arr[l][u] == NONE) return false;
	if (arr[r][d] == NONE || arr[r][u] == NONE) return false;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int tc = 1; ; ++tc) {
		int n; cin >> n;
		if (n == 0) break;

		vector<node> v(n);
		for (auto& i : v) cin >> i.lab >> i.x >> i.y;

		vector<int> xx, yy;
		for (auto& i : v) xx.push_back(i.x), yy.push_back(i.y);
		sort(xx.begin(), xx.end()), sort(yy.begin(), yy.end());
		xx.erase(unique(xx.begin(), xx.end()), xx.end());
		yy.erase(unique(yy.begin(), yy.end()), yy.end());

		for (int i = 0; i < xx.size(); ++i) for (int j = 0; j < yy.size(); ++j)
			arr[i][j] = NONE;

		for (auto& i : v) {
			i.x = lower_bound(xx.begin(), xx.end(), i.x) - xx.begin();
			i.y = lower_bound(yy.begin(), yy.end(), i.y) - yy.begin();
			arr[i.x][i.y] = i.lab;
		}

		vector<string> ans;
		for (int l = 0; l < xx.size()-1; ++l) for (int r = l+1; r < xx.size(); ++r) {
			for (int d = 0; d < yy.size()-1; ++d) for (int u = d+1; u < yy.size(); ++u) {
				if (check_rect(l, r, d, u)) {
					string cur = "";
					cur.push_back(arr[l][u]), cur.push_back(arr[r][u]);
					cur.push_back(arr[r][d]), cur.push_back(arr[l][d]);
					ans.push_back(cur);
				}
			}
		}
		sort(ans.begin(), ans.end());
		
		cout << "Point set " << tc << ": ";
		if (ans.empty()) cout << "No rectangles";
		cout << "\n";

		for (int i = 0; i < ans.size(); ++i) {
			cout << ' ' << ans[i];
			if ((i+1)%10 == 0) cout << '\n';
		}
		if (ans.size() % 10) cout << '\n';
	}	
}