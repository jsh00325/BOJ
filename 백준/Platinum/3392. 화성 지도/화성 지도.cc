// 참고: https://4legs-study.tistory.com/126

#include <bits/stdc++.h>
using namespace std;

struct line { int x, y1, y2, val; };

const int MX = 30000;
// cnt는 idx에 해당하는 범위인 [st, en]범위를 가득 채우는 선의 수를 저장
// area는 idx에 해당하는 범위인 [st, en]범위에서 선이 차지하는 영역의 크기를 저장
int cnt[4*MX+7], area[4*MX+7];

void update(int idx, int st, int en, int y1, int y2, int val) {
	if (y2 < st || en < y1) return;

	if (y1 <= st && en <= y2) cnt[idx] += val;
	else {
		int mid = (st + en) >> 1;
		update(idx<<1, st, mid, y1, y2, val);
		update((idx<<1)+1, mid+1, en, y1, y2, val);
	}

	/*
	해당 범위에 선분이 존재 -> 꽉 차있음 -> en-st+1
	해당 범위에 선분이 존재X = 꽉 차있지 않다... -> 자식의 정보를 통해서 업데이트
	*/

	if (cnt[idx]) area[idx] = en - st + 1;
	else if (st == en) area[idx] = 0;
	else area[idx] = area[idx<<1] + area[(idx<<1)+1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;

	vector<line> v;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({x1, y1, y2, 1}), v.push_back({x2, y1, y2, -1});
	}
	sort(v.begin(), v.end(), [](line& a, line& b) { return a.x < b.x; });

	int ans = 0;
	for (int i = 0; i < 2*n; ++i) {
		int dx = (i == 0 ? 0 : v[i].x - v[i-1].x);
		int dy = area[1];
		ans += dx * dy;
		update(1, 0, MX, v[i].y1, v[i].y2-1, v[i].val);
	}
	cout << ans;
}