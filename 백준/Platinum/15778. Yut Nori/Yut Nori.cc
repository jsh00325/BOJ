#include <bits/stdc++.h>
using namespace std;
#define FOR0(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for (int (i) = 1; (i) <= (n); (i)++)

string board[32] = {
	"..----..----..----..----..----..",
	"..    ..    ..    ..    ..    ..",
	"| \\                          / |",
	"|  \\                        /  |",
	"|   \\                      /   |",
	"|    ..                  ..    |",
	"..   ..                  ..   ..",
	"..     \\                /     ..",
	"|       \\              /       |",
	"|        \\            /        |",
	"|         ..        ..         |",
	"|         ..        ..         |",
	"..          \\      /          ..",
	"..           \\    /           ..",
	"|             \\  /             |",
	"|              ..              |",
	"|              ..              |",
	"|             /  \\             |",
	"..           /    \\           ..",
	"..          /      \\          ..",
	"|         ..        ..         |",
	"|         ..        ..         |",
	"|        /            \\        |",
	"|       /              \\       |",
	"..     /                \\     ..",
	"..   ..                  ..   ..",
	"|    ..                  ..    |",
	"|   /                      \\   |",
	"|  /                        \\  |",
	"| /                          \\ |",
	"..    ..    ..    ..    ..    ..",
	"..----..----..----..----..----.."
};
const int ST = 29, OUT = 30;
int x[29] = { 30,24,18,12,6,0,0,0,0,0,0,6,12,18,24,30,30,30,30,30,5,10,15,5,10,20,25,20,25 };
int y[29] = { 30,30,30,30,30,30,24,18,12,6,0,0,0,0,0,0,6,12,18,24,25,20,15,5,10,10,5,20,25 };
int d[29] = { -1,1,1,1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,1,1,-19,1,1,-1,1,-2,1,-11,1,-28 };
int di[8] = { 0,0,1,1,0,0,1,1 }, dj[8] = { 0,1,0,1,0,1,0,1 };
int cur_visit[31]; // bitmask로 방문 저장 [ 0:A / 1:B / 2:C / 3:D / 4:a / 5:b / 6:c / 7:d ]
int player_cood[8] = {ST, ST, ST, ST, ST, ST, ST, ST };
char unt[9] = "ABCDabcd";

/* prev에서 cur로 이동했을 때 적절한 다음 윷판 반환 */
int nxt(int prev, int cur) {
	if (cur == OUT) return OUT;
	if (cur == 0) return (prev == -1 ? 1 : OUT);
	if (cur == 5) return (prev == -1 ? 20 : 6);
	if (cur == 10) return (prev == -1 ? 23 : 11);
	if (cur == 22) return (prev == 21 ? 25 : 27);
	return cur + d[cur];
}
/*idx에서 val만큼 움직였을 때의 도착 위치 반환 / 탈출 -> OUT 반환*/
int move(int idx, int val) {
	int prev = -1, cur = idx;
	while (val--) {
		int temp = nxt(prev, cur);
		prev = cur; cur = temp;
	}
	return cur;
}
/* 윷의 결과에서 이동 수 구하기 */
int change(string s) {
	int cnt = 0;
	FOR0(i, 4) cnt += (s[i] == 'F');
	return (cnt ? cnt : 5);
}
void print_board() {
	FOR0(i, 29) FOR0(j, 8) if (cur_visit[i] & (1 << j))
		board[x[i] + di[j]][y[i] + dj[j]] = unt[j];
	FOR0(i, 32) cout << board[i] << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	while (n--) {
		char c; string s;
		cin >> c >> s;
		int player = (c >= 'a' ? c - 'a' + 4 : c - 'A'), roll = change(s);

		int cur = player_cood[player];
		int nxt = move((cur == ST ? 0 : cur), roll);

		int& cur_bit = cur_visit[cur];
		if (cur == ST) cur_bit = (1 << player);
		int& nxt_bit = cur_visit[nxt];

		// 플레이어가 대문자이고 도착칸에 소문자 팀이 점령 중이면
		if (player < 4 && nxt_bit && (nxt_bit >> 4)) {
			// 소문자팀 시작 전으로 보내기
			for (int k = 4; k < 8; k++)
				if (nxt_bit & (1 << k)) player_cood[k] = ST;
			nxt_bit &= (1 << 4) - 1;
		}
		// 플레이어가 소문자이고 도착칸에 대문자 팀이 점령 중이면
		else if (player >= 4 && nxt_bit && (nxt_bit & ((1 << 4) - 1))) {
			// 대문자팀 시작 전으로 보내기
			for (int k = 0; k < 4; k++)
				if (nxt_bit & (1 << k)) player_cood[k] = ST;
			nxt_bit &= (1 << 8) - (1 << 4);
		}

		FOR0(k, 8) if (cur_bit & (1 << k)) player_cood[k] = nxt;

		nxt_bit += cur_bit;
		cur_bit = 0;
	}
	print_board();
}