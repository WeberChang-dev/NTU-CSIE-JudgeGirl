#include <stdio.h>
int main() {
	int n, arr[3];
	scanf("%d", &n);
	for (int i = 2; i >= 0; i--, n /= 10) arr[i] = n - n / 10 * 10;  
	for (int i = 0; i < 3; i++) printf("%d\n", arr[i]);
	return 0;
}
