#include<stdio.h>
int main() {
	int n, tmp, cnt0 = 0, cnt1 = 0, cnt2 = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &tmp);
		if (tmp % 3 == 0) cnt0++;
		else if (tmp % 3 == 1) cnt1++;
		else cnt2++;
	}
	printf("%d %d %d", cnt0, cnt1, cnt2);
}
