#include <stdio.h>
int main() {
	int s, f, t, a, b, c;
	scanf("%d%d%d", &s, &f, &t);
	if (s - t < 0) {
		printf("0");
		return 0;
	}
	c = s - t;
	f -= 8 * c;
	if (f < 0 || (f - 2 * (s - c)) % 2) {
		printf("0");
		return 0;
	}
	b = (f - 2 * (s - c)) / 2;
	a = s - b - c;
	if (a < 0) {
		printf("0");
		return 0;
	}
	printf("%d\n%d\n%d", a, b, c);
}
