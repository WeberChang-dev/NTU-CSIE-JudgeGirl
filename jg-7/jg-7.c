#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", !(!(n % 3) && !(n % 5) && (n % 7)));
}
