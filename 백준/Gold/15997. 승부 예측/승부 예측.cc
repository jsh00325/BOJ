#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct node { int idx, val; };

double win[4][4], draw[4][4], lose[4][4], rslt[4];
unordered_map<string, int> um;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed; cout.precision(10);

	for (int i = 0; i < 4; ++i) {
		string s; cin >> s;
		um[s] = i;
	}

	for (int i = 0; i < 6; ++i) {
		string aStr, bStr; cin >> aStr >> bStr;
		int a = um[aStr], b = um[bStr];
		double w, d, l; cin >> w >> d >> l;

		if (a < b) win[a][b] = w, draw[a][b] = d, lose[a][b] = l;
		else win[b][a] = l, draw[b][a] = d, lose[b][a] = w;
	}

	for (int data = 0; data < 729; ++data) {
		int cur = data;
		double prob = 1.0;
		node point[4] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};

		for (int i = 0; i < 3; ++i) for (int j = i+1; j < 4; ++j) {
			int flag = cur % 3; cur /= 3;

			if (flag == 0) point[i].val += 3, prob *= win[i][j];
			else if (flag == 1) ++point[i].val, ++point[j].val, prob *= draw[i][j];
			else point[j].val += 3, prob *= lose[i][j];

			if (prob == 0) break;
		}
		if (prob == 0) continue;

		sort(point, point+4, [](const node& a, const node& b) {
			return a.val > b.val;
		});

		if (point[1].val == point[2].val) {
			if (point[2].val == point[3].val) {
				if (point[0].val == point[1].val) {
					// 모두 같은 경우
					rslt[point[0].idx] += prob / 2;
					rslt[point[1].idx] += prob / 2;
					rslt[point[2].idx] += prob / 2;
					rslt[point[3].idx] += prob / 2;
				}
				else {
					// 1등은 확정 & 2,3,4등을 랜덤
					rslt[point[0].idx] += prob;
					rslt[point[1].idx] += prob / 3;
					rslt[point[2].idx] += prob / 3;
					rslt[point[3].idx] += prob / 3;
				}
			}
			else if (point[0].val == point[1].val) {
				// 1,2,3등이 랜덤
				rslt[point[0].idx] += prob * 2 / 3;
				rslt[point[1].idx] += prob * 2 / 3;
				rslt[point[2].idx] += prob * 2 / 3;
			}
			else {
				// 1등은 확정 & 2,3등이 랜덤
				rslt[point[0].idx] += prob;
				rslt[point[1].idx] += prob / 2;
				rslt[point[2].idx] += prob / 2;
			}
		}
		else {
			rslt[point[0].idx] += prob;
			rslt[point[1].idx] += prob;
		}		
	}
	for (int i = 0; i < 4; ++i) cout << rslt[i] << '\n';
}