#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point {
	int i, j;
} POINT;

int n, m, wall, max, head, rear, arr[8][8];
POINT queue[100];
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
bool visit[8][8];

void push(int i, int j) {
	queue[rear].i = i;
	queue[rear].j = j;
	rear++;
	visit[i][j] = true;
}
POINT pop() { return queue[head++]; }
bool empty() { return head == rear; }
void reset() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = false;
	head = 0;
	rear = 0;
}
void bt(int c) {
	if (c == 3) {
		reset();
		int safe = n * m - wall - 3;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j] == 2) push(i, j);

		while (!empty()) {
			POINT p = pop();
			safe--;
			for (int o = 0; o < 4; o++) {
				int ni = p.i + di[o];
				int nj = p.j + dj[o];
				if (ni < 0 || ni >= n) continue;
				if (nj < 0 || nj >= m) continue;
				if (arr[ni][nj] == 1) continue;
				if (visit[ni][nj]) continue;
				push(ni, nj);
			}
		}
		if (max < safe) max = safe;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				bt(c + 1);
				arr[i][j] = 0;
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) wall++;
		}
	}
	bt(0);
	printf("%d", max);
}