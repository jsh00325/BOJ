#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

typedef struct { int x, y; } Node;
int n;
Node point[100000];

bool cmpX(const Node& a, const Node& b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}
bool cmpY(const Node& a, const Node& b) { 
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}

int getLength2(const Node& a, const Node& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int naiveLength(const vector<Node>& p, int st, int en) {
	int rslt = 0x7fffffff;
	for (int i = st; i <= en; i++)
		for (int j = i + 1; j <= en; j++)
			rslt = min(rslt, getLength2(p[i], p[j]));
	return rslt;
}

int findClosestPairLength(const vector<Node>& xSort, const vector<Node>& ySort, int st, int en) {
	if (en - st + 1 <= 3) return naiveLength(xSort, st, en);
	
	int mid = (st + en) / 2;
	Node midPoint = xSort[mid];

	vector<Node> nxtYSortLeft, nxtYSortRight;
	FOR(i, ySort.size())
		if ((ySort[i].x < midPoint.x || (ySort[i].x == midPoint.x && ySort[i].y <= midPoint.y)) && nxtYSortLeft.size() <= mid - st)
			nxtYSortLeft.push_back(ySort[i]);
		else
			nxtYSortRight.push_back(ySort[i]);
	
	int minD = min(
		findClosestPairLength(xSort, nxtYSortLeft, st, mid), 
		findClosestPairLength(xSort, nxtYSortRight, mid + 1, en));
    if (!minD) return 0;

	vector<Node> mergePointYSort;	// 합치면서 확인해야 할 영역에 있는 점들 (Y 정렬됨)
	for (Node ySortItem : ySort)
		if ((ySortItem.x - midPoint.x)* (ySortItem.x - midPoint.x) < minD)
			mergePointYSort.push_back(ySortItem);
	
	int mergeDist = 0x7fffffff;
	FOR(i, mergePointYSort.size()) for (int j = i + 1; j < mergePointYSort.size(); j++) {
		if (mergePointYSort[j].y - mergePointYSort[i].y >= minD) break;
		mergeDist = min(mergeDist, getLength2(mergePointYSort[i], mergePointYSort[j]));
	}
	return min(minD, mergeDist);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR(i, n) cin >> point[i].x >> point[i].y;

	vector<Node> xSort(n), ySort(n);
	FOR(i, n) xSort[i] = ySort[i] = point[i];
	sort(xSort.begin(), xSort.end(), cmpX);
	sort(ySort.begin(), ySort.end(), cmpY);
	cout << findClosestPairLength(xSort, ySort, 0, n-1);
}