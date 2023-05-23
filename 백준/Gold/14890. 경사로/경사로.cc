#include <iostream>
using namespace std;

int n, l, map[101][101], road[101], cnt;
bool visit[101];

void func() {
	for (int i = 0; i < n; i++) visit[i] = false;
	for (int i = 0; i < n - 1; i++) {
		if (abs(road[i] - road[i + 1]) > 1) return;
	}

	int noUp = 1;
	for (int i = 0; i < n - 1; i++) {
		if (road[i] < road[i + 1]) {
			if (noUp < l) return;
			else if(visit[i-l+1]) return;
			else noUp = 1;
		}
		else if (road[i] > road[i+1]) {
			if (road[i + 1] == road[i + l]) {
				for (int q = 0; q < l; q++) visit[i + q + 1] = true;
				noUp = 1;
			}
			else return;
		}
		else noUp++;
	}
	cnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			road[j] = map[i][j];
		func();
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++)
			road[i] = map[i][j];
		func();
	}
    
	cout << cnt;
}