#include <bits/stdc++.h>
using namespace std;
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); ++(i))

const int INF = 0x3f3f3f3f, MX = 401;
int v, e, a, b, d[MX][MX], ans = INF;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> v >> e;
	FOR1(i, v) FOR1(j, v) d[i][j] = INF;
	while (e--) cin >> a >> b, cin >> d[a][b];
	
	FOR1(k, v) FOR1(i, v) FOR1(j, v)
	    if (d[i][j] > d[i][k] + d[k][j])
	        d[i][j] = d[i][k] + d[k][j];
	  
	FOR1(i, v) if (ans > d[i][i])
	    ans = d[i][i];
	cout << (ans == INF ? -1 : ans);
}