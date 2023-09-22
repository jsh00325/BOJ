int main() {
	char check=0, post = 0 ,input=0; int cnt = 0;
	while (1) {
		input = getchar();
		if (check == 1 && input == 32) cnt++;
		if (65 <= input) check = 1;
		else check = 0;
		if (input == 10) break;
		post = check;
	}
	printf("%d", (post == 0 ? cnt :cnt+1));
}