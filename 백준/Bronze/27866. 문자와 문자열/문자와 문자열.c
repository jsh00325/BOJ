#include <stdio.h>

int main(void) {
	char str[1001];
	int i;
	scanf("%s %d", str, &i);
	printf("%c", str[i-1]);
	return 0;
}