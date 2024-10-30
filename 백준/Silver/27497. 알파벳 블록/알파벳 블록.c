#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE (1<<4)
#define MAX_SIZE (1<<30)

typedef enum { false, true } bool;
typedef struct {
    int time;
    char ch;
} element;
typedef struct {
    element *data;
    int capacity;
    int front, rear;
} Deque;

void initDeque(Deque *d) {
    d->capacity = INITIAL_SIZE;
    d->data = (element*)malloc(sizeof(element) * d->capacity);
    d->front = d->rear = (d->capacity >> 1);
}

bool isEmptyDeque(Deque *d) {
    return d->front == d->rear;
}

bool __isFullDeque(Deque *d) {
    return ((d->rear + 1) % d->capacity) == d->front;
}

void __expandDeque(Deque *d) {
    int prevCapacity = d->capacity;

    if ((d->capacity <<= 1) > MAX_SIZE) exit(0);
    d->data = (element*)realloc(d->data, sizeof(element) * d->capacity);

    if (d->front > d->rear) {
        for (int idx = d->front; idx < prevCapacity; ++idx) {
            d->data[idx + prevCapacity] = d->data[idx];
        }

        d->front += prevCapacity;
    }
}

void pushFrontDeque(Deque *d, element value) {
    if (__isFullDeque(d)) __expandDeque(d);

    d->front = (d->front + d->capacity - 1) % d->capacity;
    d->data[d->front] = value;
}

void pushBackDeque(Deque *d, element value) {
    if (__isFullDeque(d)) __expandDeque(d);

    d->data[d->rear] = value;
    d->rear = (d->rear + 1) % d->capacity;
}

element popFrontDeque(Deque *d) {
    if (isEmptyDeque(d)) exit(0);
    
    element result = d->data[d->front];
    d->front = (d->front + 1) % d->capacity;
    return result;
}

element popBackDeque(Deque *d) {
    if (isEmptyDeque(d)) exit(0);
    
    d->rear = (d->rear + d->capacity - 1) % d->capacity;
    return d->data[d->rear];
}

int main() {
    Deque d;
    initDeque(&d);

    int n;
    scanf("%d", &n); getchar();

    for (int time = 0; time < n; ++time) {
        int op;
        scanf("%d", &op); getchar();

        if (op == 1) {
            element cur = {time, 0};
            scanf("%c", &cur.ch); getchar();
            pushBackDeque(&d, cur);
        }
        else if (op == 2) {
            element cur = {time, 0};
            scanf("%c", &cur.ch); getchar();
            pushFrontDeque(&d, cur);
        }
        else {
            if (isEmptyDeque(&d)) continue;

            element front = popFrontDeque(&d);
            if (isEmptyDeque(&d)) continue;
            element back = popBackDeque(&d);

            if (front.time < back.time) pushFrontDeque(&d, front);
            else pushBackDeque(&d, back);
        }
    }

    if (isEmptyDeque(&d)) printf("0");
    else {
        while (!isEmptyDeque(&d)) {
            printf("%c", popFrontDeque(&d).ch);
        }
    }
}