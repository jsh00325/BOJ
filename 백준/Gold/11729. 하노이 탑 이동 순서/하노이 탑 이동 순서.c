#include <stdio.h>
#define P(a, b) printf("%d %d\n", a, b)

void hanoi(int level, int st, int mid, int en) {
    if (level == 1) P(st, en);
    else {
        hanoi(level-1, st, en, mid);
        P(st, en);
        hanoi(level-1, mid, st, en);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(n, 1, 2, 3);
}