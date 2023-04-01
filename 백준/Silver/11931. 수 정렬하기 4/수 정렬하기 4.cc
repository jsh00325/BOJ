#include <iostream>
using namespace std;
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)

const int MX = 1000000;
int arr[MX], temp[MX];

void merge(int s, int e) {
	int mid = (s + e) / 2;
	int i = s, j = mid + 1, k = s;
	while (i <= mid && j <= e)
		if (arr[i] > arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= e) temp[k++] = arr[j++];
	for (int x = s; x <= e; x++) arr[x] = temp[x];
}
void merge_sort(int s, int e) {
	if (s == e) return;
	int mid = (s + e) / 2;
	merge_sort(s, mid);
	merge_sort(mid + 1, e);
	merge(s, e);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	FOR(i, n) cin >> arr[i];
	merge_sort(0, n - 1);
	FOR(i, n) cout << arr[i] << '\n';
}