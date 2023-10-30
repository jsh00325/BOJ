#include <bits/stdc++.h>
using namespace std;
struct node { int x, y; };

const int MX = 0x7fffffff, MN = -1, SZ = 50000;
node arr[SZ];
bool isRemove[SZ];
int n, xV[SZ], yV[SZ];

int bt(int cnt, int mnX, int mxX, int mnY, int mxY) {
	while(isRemove[xV[mnX]]) ++mnX;
	while(isRemove[xV[mxX]]) --mxX;
	while(isRemove[yV[mnY]]) ++mnY;
	while(isRemove[yV[mxY]]) --mxY;

	if (cnt == 3) return (arr[xV[mxX]].x - arr[xV[mnX]].x) * (arr[yV[mxY]].y - arr[yV[mnY]].y);
	
	int ret = 0x7fffffff;
	
	isRemove[xV[mnX]] = true;
	ret = min(ret, bt(cnt+1, mnX+1, mxX, mnY, mxY));
	isRemove[xV[mnX]] = false;

	isRemove[xV[mxX]] = true;
	ret = min(ret, bt(cnt+1, mnX, mxX-1, mnY, mxY));
	isRemove[xV[mxX]] = false;

	isRemove[yV[mnY]] = true;
	ret = min(ret, bt(cnt+1, mnX, mxX, mnY+1, mxY));
	isRemove[yV[mnY]] = false;

	isRemove[yV[mxY]] = true;
	ret = min(ret, bt(cnt+1, mnX, mxX, mnY, mxY-1));
	isRemove[yV[mxY]] = false;

	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i].x >> arr[i].y;
	for (int i = 0; i < n; ++i) xV[i] = yV[i] = i;

	sort(xV, xV + n, [&](const int& a, const int& b) { return arr[a].x < arr[b].x; });
	sort(yV, yV + n, [&](const int& a, const int& b) { return arr[a].y < arr[b].y; });

	cout << bt(0, 0, n-1, 0, n-1);
}