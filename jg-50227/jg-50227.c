#include<stdio.h>

int min(int x, int y) {
	return ((x < y) ? x : y);
}

int main() {
	int a, b, c, d, found = 0;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for (int i = 216; i > 0; i--) {
		for (int j = min(i - 1, a - i); j > 0; j--) {
			for (int k = min(j - 1, a - i - j); k > 0; k--) {
				int l = a - i - j - k;
				if (l <= 0 || l >= k) continue;
				if (i * i + j * j + k * k + l * l == b && i * i * i + j * j * j + k * k * k + l * l * l == c && i * i * i * i + j * j * j * j + k * k * k * k + l * l * l * l == d) {
					printf("%d\n%d\n%d\n%d", i, j, k, l);
					found = 1;
					break;
				}
			}
		}
	}
	if (!found) printf("-1");
}
