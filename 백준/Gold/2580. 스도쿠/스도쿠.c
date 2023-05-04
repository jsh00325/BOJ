#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int empty;
int arr[9][9];
bool visit[9][9];

bool check_i(int i) { // 열 중복 체크 (ㅡ)
	int visit9[10] = { 0, };
	for (int x = 0; x < 9; x++) {
		if (arr[i][x] == 0) continue;
		if (visit9[arr[i][x]] == 0) visit9[arr[i][x]] = 1;
		else return false;
	}
	return true;
}
bool check_j(int j) { // 행 중복 체크 (ㅣ)
	int visit9[10] = { 0, };
	for (int x = 0; x < 9; x++) {
		if (arr[x][j] == 0) continue;
		if (visit9[arr[x][j]] == 0) visit9[arr[x][j]] = 1;
		else return false;
	}
	return true;
}
bool check_33(int i, int j) { // 칸 중복 체크(ㅁ)
	int visit9[10] = { 0, };
	int y = (i / 3) * 3;
	int x = (j / 3) * 3;
	for (int a = y; a < y + 3; a++) {
		for (int b = x; b < x + 3; b++) {
			if (arr[a][b] == 0) continue;
			if (visit9[arr[a][b]] == 0) visit9[arr[a][b]] = 1;
			else return false;
		}
	}
	return true;
}
bool find(int* i, int* j) {
	for (int a = 0; a < 9; a++) {
		for (int b = 0; b < 9; b++) {
			if (arr[a][b] == 0) {
				*i = a;
				*j = b;
				return true;
			}
		}
	}
	return false;
}

void bt(int i, int j, int count) {
	if (count == -1) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", arr[i][j]);
			printf("\n");
		}
		exit(0);
		return;
	}
	for (int n = 1; n <= 9; n++) {
		arr[i][j] = n;
		if (check_33(i, j) && check_i(i) && check_j(j) && !visit[i][j]) {
			visit[i][j] = true;
			int ni, nj;
			if (find(&ni, &nj)) bt(ni, nj, count + 1);
			else bt(0, 0, -1);
			visit[i][j] = false;
		}
		arr[i][j] = 0;
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0) empty++;
		}
	}
	int i, j;
	find(&i, &j);
	bt(i, j, 0);
}