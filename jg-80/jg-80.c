#include<stdio.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
int main() {
	int n, aX, aY, bX, bY, cX, cY, a, b, c;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d%d%d%d", &aX, &aY, &bX, &bY, &cX, &cY);
		a = (bX - cX) * (bX - cX) + (bY - cY) * (bY - cY);
		b = (aX - cX) * (aX - cX) + (aY - cY) * (aY - cY);
		c = (aX - bX) * (aX - bX) + (aY - bY) * (aY - bY);
		if (a == b || b == c || c == a) printf("isosceles\n");
		else if (a + b == c || b + c == a || a + c == b) printf("right\n");
		else if (max(a, max(b, c)) > a + b + c - max(a, max(b, c))) printf("obtuse\n");
		else printf("acute\n");
	}
}
