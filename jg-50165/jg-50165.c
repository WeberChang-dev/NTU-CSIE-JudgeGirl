#include <stdio.h>
#include <math.h>

double dis(double l1[3], double l2[3], double l3[3]) {
	double x1, x2, y1, y2, ret = 0;
	x1 = (-1 * l1[2] * l2[1] + l2[2] * l1[1]) / (l1[0] * l2[1] - l2[0] * l1[1]);
	x2 = (-1 * l2[2] * l3[1] + l3[2] * l2[1]) / (l2[0] * l3[1] - l3[0] * l2[1]);
	y1 = (-1 * l1[2] * l2[0] + l2[2] * l1[0]) / (l1[1] * l2[0] - l2[1] * l1[0]);
	y2 = (-1 * l2[2] * l3[0] + l3[2] * l2[0]) / (l2[1] * l3[0] - l3[1] * l2[0]);
	ret += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return ret;
}

int main() {
	int n;
	double ans = 0, lines[255][3];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%lf", &lines[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		ans += dis(lines[i], lines[(i + 1) % n], lines[(i + 2) % n]);	
	}
	printf("%.3lf", ans);
}
