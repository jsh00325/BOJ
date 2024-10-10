#include <stdio.h>

int solve() {
    char targetString[60];
    scanf("%s", targetString);

    int topIndex = 0;
    for (int i = 0; targetString[i] != '\0'; ++i) {
        if (targetString[i] == '(') ++topIndex;
        else if (topIndex == 0) return 0;
        else --topIndex;
    }
    return topIndex == 0;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
        printf("%s\n", solve() ? "YES" : "NO");
}