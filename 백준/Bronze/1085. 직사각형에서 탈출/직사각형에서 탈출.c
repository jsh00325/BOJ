int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	w -= x; h -= y;
	x = (x < y ? x : y);
	y = (w < h ? w : h);
	printf("%d", x < y ? x : y);
}