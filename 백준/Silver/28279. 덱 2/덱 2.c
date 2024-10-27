#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY (1<<4)
#define MAX_CAPACITY (1<<30)

void printError(const char *errorInfo) {
    fprintf(stderr, "%s\n", errorInfo);
    exit(1);
}

typedef int element;
typedef enum { false = 0, true = 1 } bool;
typedef struct deque {
    element *data;
    int capacity;
    int front, rear;
} Deque;

void initDeque(Deque *d) {
    d->capacity = INITIAL_CAPACITY;
    d->data = (element*)malloc(sizeof(element) * (d->capacity));
    d->front = d->rear = 0;
}

bool __isFullDeque(Deque *d) {
    return ((d->rear + 1) % d->capacity) == d->front;
}

void __expandDeque(Deque *d) {
    int prevCapacity = d->capacity;
    if (((d->capacity) <<= 1) > MAX_CAPACITY) printError("Deque size has reached it`s limit.");
    d->data = (element*)realloc(d->data, sizeof(element) * (d->capacity));

    if ((d->front) <= (d->rear)) return;
    
    for (int idx = d->front; idx < prevCapacity; ++idx)
        d->data[idx + prevCapacity] = d->data[idx];

    (d->front) += prevCapacity;
}

bool isEmptyDeque(Deque *d) {
    return (d->front) == (d->rear);
}

int getDequeSize(Deque *d) {
    if ((d->rear) >= (d->front)) return (d->rear) - (d->front);
    else return (d->rear) - (d->front) + (d->capacity);
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
    if (isEmptyDeque(d)) printError("Deque is Empty.");

    element frontElement = d->data[d->front];
    d->front = (d->front + 1) % d->capacity;
    return frontElement;
}

element popBackDeque(Deque *d) {
    if (isEmptyDeque(d)) printError("Deque is Empty.");

    d->rear = (d->rear + d->capacity - 1) % d->capacity;
    return d->data[d->rear];
}

element getFrontDeque(Deque *d) {
    if (isEmptyDeque(d)) printError("Deque is Empty.");
    else return d->data[d->front];
}

element getBackDeque(Deque *d) {
    if (isEmptyDeque(d)) printError("Deque is Empty.");
    else return d->data[(d->rear + d->capacity - 1) % d->capacity];
}

int main() {
    int N;
    scanf("%d", &N);

    Deque d;
    initDeque(&d);

    while (N--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x; scanf("%d", &x);
            pushFrontDeque(&d, x);
        } else if (op == 2) {
            int x; scanf("%d", &x);
            pushBackDeque(&d, x);
        } else if (op == 3) {
            printf("%d\n", isEmptyDeque(&d) ? -1 : popFrontDeque(&d));
        } else if (op == 4) {
            printf("%d\n", isEmptyDeque(&d) ? -1 : popBackDeque(&d));
        } else if (op == 5) {
            printf("%d\n", getDequeSize(&d));
        } else if (op == 6) {
            printf("%d\n", isEmptyDeque(&d));
        } else if (op == 7) {
            printf("%d\n", isEmptyDeque(&d) ? -1 : getFrontDeque(&d));
        } else if (op == 8) {
            printf("%d\n", isEmptyDeque(&d) ? -1 : getBackDeque(&d));
        }
    }
}