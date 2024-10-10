int main() {
	int n; scanf("%d", &n);
	char str[51];
	for (int x = 0; x < n; x++) {
		int check[51] = { 0, };
		int cnt = 1;
		scanf("%s", str);
		for (int i = 0; i < 50; i++) {
			if (str[i] == '\0') break;
			else if (str[i] == '(') check[cnt++]++;
			else if (str[i] == ')') check[--cnt]--;
			if (check[0] == -1) {
				cnt = -1; break;
			}
		}
		if (cnt == -1) printf("NO\n");
		else {
			for (int i = 1; i <= 50; i++) {
				if (check[i] == 0) continue;
				else {
					printf("NO\n");
					cnt = -1;
					break;
				}
			}
			if (cnt != -1) printf("YES\n");
		}
	}
}