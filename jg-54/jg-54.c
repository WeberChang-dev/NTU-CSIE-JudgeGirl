#include<stdio.h>
int main() {
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	int twoDigits = m - m / 100 * 100;
	m /= 100;
	for (int i = 0; i < 6; i++, m /= 10) {
		if (n == twoDigits)
			ans++;
		twoDigits = (m - m / 10 * 10) * 10 + twoDigits / 10;
	}
	printf("%d", ans);
}
