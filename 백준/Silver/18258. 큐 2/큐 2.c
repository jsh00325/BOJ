#include <stdio.h>
#include <string.h>
#define MX 2000000

int queue[MX+3], front, rear;

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "push") == 0) {
            int x; scanf("%d", &x);
            queue[rear++] = x;
        } else if (strcmp(op, "pop") == 0) {
            if (front == rear) printf("-1\n");
            else printf("%d\n", queue[front++]);
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", rear - front);
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", front == rear);
        } else if (strcmp(op, "front") == 0) {
            if (front == rear) printf("-1\n");
            else printf("%d\n", queue[front]);
        } else if (strcmp(op, "back") == 0) {
            if (front == rear) printf("-1\n");
            else printf("%d\n", queue[rear-1]);
        }
    }
}