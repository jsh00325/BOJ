#include <bits/stdc++.h>
using namespace std;

const int MX = 2003;
struct node { int node_num, input_num; };
int n, a, b, node_cnt, ipt[MX], opt[MX], p[MX], lv[MX];
vector<int> edge[MX];
string s;

void set_level(int cur) {
	for (auto& nxt : edge[cur]) {
		lv[nxt] = lv[cur] + 1;
		set_level(nxt);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s >> a >> b;

	stack<node> st;
	st.push({2002, 2002});
	for (int i = 0; i < 2*n; ++i) {
		if (s[i] == '0') st.push({node_cnt++, i+1});
		else {
			node cur = st.top(); st.pop();
			ipt[cur.node_num] = cur.input_num;
			opt[cur.node_num] = i+1;
			p[cur.node_num] = st.top().node_num;
			edge[st.top().node_num].push_back(cur.node_num);
		}
	}
	set_level(0);

	for (int i = 0; i < n; ++i) if (ipt[i] == a || opt[i] == a) { a = i; break; }
	for (int i = 0; i < n; ++i) if (ipt[i] == b || opt[i] == b) { b = i; break; }

	while (lv[a] < lv[b]) b = p[b];
	while (lv[a] > lv[b]) a = p[a];
	while (a != b) a = p[a] , b = p[b];

	cout << ipt[a] << ' ' << opt[a];
}