#include <stdio.h>
int main() {
	int s, f, t, a, b, c;
	scanf("%d%d%d", &s, &f, &t);
	c = s - t;
	f -= 8 * c;
	b = (f - 2 * (s - c)) / 2;
	a = s - b - c;
	printf("%d\n%d\n%d", a, b, c);
}
