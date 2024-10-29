#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE (1<<4)
#define MAX_SIZE (1<<30)

typedef struct { int idx, value; } element;
typedef enum { false, true } bool;
typedef struct stack {
    element *data;
    int capacity;
    int top_idx;
} Stack;

void initStack(Stack *s) {
    s->capacity = INITIAL_SIZE;
    s->data = (element*)malloc(sizeof(element) * s->capacity);
    s->top_idx = 0;
}

bool __isFullStack(Stack *s) {
    return s->top_idx == s->capacity;
}

void __expandStack(Stack *s) {
    if ((s->capacity <<= 1) > MAX_SIZE) exit(0);
    s->data = (element*)realloc(s->data, sizeof(element) * s->capacity);
}

bool isEmptyStack(Stack *s) {
    return s->top_idx == 0;
}

void pushStack(Stack *s, element value) {
    if (__isFullStack(s)) __expandStack(s);

    s->data[(s->top_idx)++] = value;
}

element popStack(Stack *s) {
    if (isEmptyStack(s)) exit(0);
    return s->data[--(s->top_idx)];
}

element getTopStack(Stack *s) {
    if (isEmptyStack(s)) exit(0);
    return s->data[s->top_idx - 1];
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    Stack s;
    initStack(&s);

    int *result = (int*)malloc(sizeof(int) * n);
    memset(result, 0, sizeof(int) * n);

    for (int i = n-1; i >= 0; --i) {
        element cur = {i, arr[i]};
        
        while (!isEmptyStack(&s)) {
            element top = popStack(&s);

            if (top.value < cur.value) result[top.idx] = cur.idx + 1;
            else {
                pushStack(&s, top);
                break;
            }
        }
        pushStack(&s, cur);
    }

    for (int i = 0; i < n; ++i) printf("%d ", result[i]);
}