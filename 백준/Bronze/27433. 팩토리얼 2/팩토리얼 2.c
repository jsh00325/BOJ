#include <stdio.h>

long long fact(int n) {
	if (n == 0) return 1;
	else return n * fact(n - 1);
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%lld", fact(n));
}