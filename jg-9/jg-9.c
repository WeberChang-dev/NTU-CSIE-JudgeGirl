#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if (n <= 0) {
		printf("-100");
		return 0;
	}
	int score = 0;
	if (n % 3 == 0) score += 3;
	if (n % 5 == 0) score += 5;
	if (n >= 100 && n <= 200) score += 50;
	else score -= 50;
	printf("%d", score);
}
