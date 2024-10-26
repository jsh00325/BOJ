#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 1000001

typedef enum {
    false = 0, true = 1
} bool;

typedef struct stack {
    int* data;
    int top;
} Stack;

void initStack(Stack *s, int n) {
    s->data = (int*)malloc(sizeof(int) * n);
    s->top = 0;
}

void pushStack(Stack *s, int value) {
    s->data[(s->top)++] = value;
}

bool isEmptyStack(Stack *s) {
    return (s->top) == 0;
}

int getStackSize(Stack *s) {
    return (s->top);
}

int popStack(Stack *s) {
    return s->data[--(s->top)];
}

int topStack(Stack *s) {
    return s->data[(s->top) - 1];
}

int main() {
    Stack s;
    int n, op, x;
    scanf("%d", &n);
    initStack(&s, n);

    while (n--) {
        scanf("%d", &op);

        switch (op) {
        case 1:
            scanf("%d", &x);
            pushStack(&s, x);
            break;
        
        case 2:
            if (isEmptyStack(&s)) printf("-1\n");
            else printf("%d\n", popStack(&s));
            break;
        
        case 3:
            printf("%d\n", getStackSize(&s));
            break;
        
        case 4:
            printf("%d\n", isEmptyStack(&s));
            break;
        
        case 5:
            if (isEmptyStack(&s)) printf("-1\n");
            else printf("%d\n", topStack(&s));
            break;
        
        default:
            break;
        }
    }

    free(s.data);
    return 0;
}