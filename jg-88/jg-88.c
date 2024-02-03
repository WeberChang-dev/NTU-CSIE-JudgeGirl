#include<stdio.h>

int getNthDigit(int x, int n) {
	int cpy = x;
	for (int i = 0; i < n; i++) cpy /= 10;
	for (int i = 0; i < n; i++) cpy *= 10;
	int ret = x - cpy;
	for (int i = 1; i < n; i++) ret /= 10;
	return ret;
}

int main() {
	int A = 0, B = 0, m, n;
	scanf("%d %d", &n, &m);	
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (getNthDigit(n, i) == getNthDigit(m, j)) {
				if (i == j) A++;
				else B++;
			}
		}
	}
	printf("%dA%dB", A, B);
}
