#include <bits/stdc++.h>
using namespace std;
struct node { int x, y, z; };

int asc_con[200];

bool cmp(const string& a, const string& b) {
	return asc_con[a[0]] < asc_con[b[0]];
}

int straight_flush(vector<string>& v) {
	for (int i = 1; i < 5; ++i) if (v[0][1] != v[i][1]) return 0;
	for (int i = 1; i < 5; ++i) if (asc_con[v[i-1][0]] + 1 != asc_con[v[i][0]]) return 0;
	return asc_con[v[0][0]];
}
int four_of_a_kind(vector<string>& v) {
	bool f1 = true, f2 = true;
	for (int i = 2; i < 5; i++) if (v[1][0] != v[i][0]) f1 = false;
	for (int i = 1; i < 4; i++) if (v[0][0] != v[i][0]) f2 = false;
	return (f1 || f2 ? asc_con[v[2][0]] : 0);
}
int full_house(vector<string>& v) {
	if (v[0][0] != v[1][0] || v[3][0] != v[4][0]) return 0;
	if (v[1][0] == v[2][0] || v[2][0] == v[3][0]) return asc_con[v[2][0]];
	return 0;
}
int m_flush(vector<string>& v) {
	for (int i = 1; i < 5; ++i) if (v[0][1] != v[i][1]) return 0;
	return asc_con[v[4][0]];
}
int straight(vector<string>& v) {
	for (int i = 1; i < 5; ++i) if (asc_con[v[i-1][0]] + 1 != asc_con[v[i][0]]) return 0;
	return asc_con[v[4][0]];
}
int three_of_a_kind(vector<string>& v) {
	if (v[0][0] == v[1][0] && v[1][0] == v[2][0]) return asc_con[v[2][0]];
	if (v[1][0] == v[2][0] && v[2][0] == v[3][0]) return asc_con[v[2][0]];
	if (v[2][0] == v[3][0] && v[3][0] == v[4][0]) return asc_con[v[2][0]];
	return 0;
}
node two_pairs(vector<string>& v) {
	if (v[0][0] == v[1][0] && v[2][0] == v[3][0]) return {asc_con[v[3][0]], asc_con[v[1][0]], asc_con[v[4][0]]};
	if (v[0][0] == v[1][0] && v[3][0] == v[4][0]) return {asc_con[v[4][0]], asc_con[v[1][0]], asc_con[v[2][0]]};
	if (v[1][0] == v[2][0] && v[3][0] == v[4][0]) return {asc_con[v[4][0]], asc_con[v[2][0]], asc_con[v[0][0]]};
	return {0, 0, 0};
}
int m_pair(vector<string>& v) {
	for (int i = 1; i < 5; ++i) if (v[i-1][0] == v[i][0]) return asc_con[v[i][0]];
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 2; i < 10; ++i) asc_con['0'+i] = i;
	asc_con['T'] = 10, asc_con['J'] = 11, asc_con['Q'] = 12, asc_con['K'] = 13, asc_con['A'] = 14;

	string s;
	while (getline(cin, s)) {
		vector<string> b, w;
		for (int i = 0; i < 15; i += 3) b.push_back(s.substr(i, 2));
		for (int i = 15; i < 30; i += 3) w.push_back(s.substr(i, 2));
		sort(b.begin(), b.end(), cmp), sort(w.begin(), w.end(), cmp);

		// check straight flush
		int b_sf = straight_flush(b), w_sf = straight_flush(w);
		if (b_sf && w_sf) {
			if (b_sf > w_sf) cout << "Black wins.\n";
			else if (b_sf < w_sf) cout << "White wins.\n";
			else cout << "Tie.\n";
			continue;
		}
		else if (b_sf && !w_sf) { cout << "Black wins.\n"; continue; }
		else if (!b_sf && w_sf) { cout << "White wins.\n"; continue; }

		// check four of a kind
		int b_fk = four_of_a_kind(b), w_fk = four_of_a_kind(w);
		if (b_fk && w_fk) {
			if (b_fk > w_fk) cout << "Black wins.\n";
			else if (b_fk < w_fk) cout << "White wins.\n";
			else cout << "Tie.\n";
			continue;
		}
		else if (b_fk && !w_fk) { cout << "Black wins.\n"; continue; }
		else if (!b_fk && w_fk) { cout << "White wins.\n"; continue; }

		// check full house
		int b_fh = full_house(b), w_fh = full_house(w);
		if (b_fh && w_fh) {
			if (b_fh > w_fh) cout << "Black wins.\n";
			else if (b_fh < w_fh) cout << "White wins.\n";
			else cout << "Tie.\n";
			continue;
		}
		else if (b_fh && !w_fh) { cout << "Black wins.\n"; continue; }
		else if (!b_fh && w_fh) { cout << "White wins.\n"; continue; }

		// check flush
		int b_f = m_flush(b), w_f = m_flush(w);
		if (b_f && w_f) {
			bool is_end = false;
			for (int i = 4; i >= 0; --i) {
				int curB = asc_con[b[i][0]], curW = asc_con[w[i][0]];
				if (curB > curW) { cout << "Black wins.\n"; is_end = true; break; }
				else if (curB < curW) { cout << "White wins.\n"; is_end = true; break; }
			} if (!is_end) cout << "Tie.\n";
			continue;
		}
		else if (b_f && !w_f) { cout << "Black wins.\n"; continue; }
		else if (!b_f && w_f) { cout << "White wins.\n"; continue; }

		// check straight
		int b_s = straight(b), w_s = straight(w);
		if (b_s && w_s) {
			if (b_s > w_s) cout << "Black wins.\n";
			else if (b_s < w_s) cout << "White wins.\n";
			else cout << "Tie.\n";
			continue;
		}
		else if (b_s && !w_s) { cout << "Black wins.\n"; continue; }
		else if (!b_s && w_s) { cout << "White wins.\n"; continue; }

		// check Three of a kind
		int b_tk = three_of_a_kind(b), w_tk = three_of_a_kind(w);
		if (b_tk && w_tk) {
			if (b_tk > w_tk) cout << "Black wins.\n";
			else if (b_tk < w_tk) cout << "White wins.\n";
			else cout << "Tie.\n";
			continue;
		}
		else if (b_tk && !w_tk) { cout << "Black wins.\n"; continue; }
		else if (!b_tk && w_tk) { cout << "White wins.\n"; continue; }

		// check two pairs
		node b_tp = two_pairs(b), w_tp = two_pairs(w);
		if (b_tp.x && w_tp.x) {
			if (b_tp.x > w_tp.x) cout << "Black wins.\n";
			else if (b_tp.x < w_tp.x) cout << "White wins.\n";
			else if (b_tp.y > w_tp.y) cout << "Black wins.\n";
			else if (b_tp.y < w_tp.y) cout << "White wins.\n";
			else if (b_tp.z > w_tp.z) cout << "Black wins.\n";
			else if (b_tp.z < w_tp.z) cout << "White wins.\n";
			else cout << "Tie.\n";
			continue;
		}
		else if (b_tp.x && !w_tp.x) { cout << "Black wins.\n"; continue; }
		else if (!b_tp.x && w_tp.x) { cout << "White wins.\n"; continue; }

		// check pair
		int b_p = m_pair(b), w_p = m_pair(w);
		if (b_p && w_p) {
			vector<int> b_d, w_d;
			for (int i = 4; i >= 0; --i) if (asc_con[b[i][0]] != b_p) b_d.push_back(asc_con[b[i][0]]);
			for (int i = 4; i >= 0; --i) if (asc_con[w[i][0]] != w_p) w_d.push_back(asc_con[w[i][0]]);

			if (b_p > w_p) { cout << "Black wins.\n"; continue; }
			else if (b_p < w_p) { cout << "White wins.\n"; continue; }
			bool is_end = false;
			for (int i = 2; i >= 0; --i) {
				if (b_d[i] > w_d[i]) { cout << "Black wins.\n"; is_end = true; break; }
				else if (b_d[i] < w_d[i]) { cout << "White wins.\n"; is_end = true; break; }
			} if (!is_end) cout << "Tie.\n";
			continue;
		}
		else if (b_p && !w_p) { cout << "Black wins.\n"; continue; }
		else if (!b_p && w_p) { cout << "White wins.\n"; continue; }

		// last High Card
		bool is_end = false;
		for (int i = 4; i >= 0; --i) {
			int b_h = asc_con[b[i][0]], w_h = asc_con[w[i][0]];
			if (b_h > w_h) { cout << "Black wins.\n"; is_end = true; break; }
			else if (b_h < w_h) { cout << "White wins.\n"; is_end = true; break; }
		} if (!is_end) cout << "Tie.\n";
	}
}