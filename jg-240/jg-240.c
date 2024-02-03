#include<stdio.h>

int cross(int x1, int y1, int x2, int y2) {
	return (x1 * y2 - x2 * y1);
} 

int main() {
	int n, x[4], y[4], len[4], dot[4];
	scanf("%d", &n);
	while (n--) {
		for (int i = 0; i < 4; i++) scanf("%d%d", &x[i], &y[i]);
		for (int i = 1; i < 4; i++) {
			int j = 1, k = 1;
			for (j; j < 4; j++) 
				if (j != i) 
					break;
			for (k; k < 4; k++) 
				if (k != i && k != j) 
					break;
			int cross1 = cross(x[0] - x[i], y[0] - y[i], x[j] - x[0], y[j] - y[0]), cross2 = cross(x[0] - x[i], y[0] - y[i], x[k] - x[0], y[k] - y[0]);
			if ((cross1 < 0 && cross2 > 0) || (cross1 > 0 && cross2 < 0)) {
			#ifdef DEBUG	
				printf("%d\n", i);
			#endif
				len[0] = (x[0] - x[j]) * (x[0] - x[j]) + (y[0] - y[j]) * (y[0] - y[j]); 
				len[1] = (x[0] - x[k]) * (x[0] - x[k]) + (y[0] - y[k]) * (y[0] - y[k]); 
				len[2] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]); 
				len[3] = (x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]); 
				dot[0] = (x[0] - x[j]) * (x[0] - x[k]) + (y[0] - y[j]) * (y[0] - y[k]);
				dot[1] = (x[0] - x[j]) * (x[i] - x[j]) + (y[0] - y[j]) * (y[i] - y[j]);
				dot[2] = (x[i] - x[j]) * (x[i] - x[k]) + (y[i] - y[j]) * (y[i] - y[k]);
				dot[3] = (x[i] - x[k]) * (x[0] - x[k]) + (y[i] - y[k]) * (y[0] - y[k]);
				if (len[0] == len[1] && len[0] == len[2] && len[0] == len[3] && dot[0] == 0 && dot[1] == 0 && dot[2] == 0 && dot[3] == 0) {
					printf("square\n");
				} else if (len[0] == len[1] && len[0] == len[2] && len[0] == len[3]) {
					printf("diamond\n");
				} else if (dot[0] == 0 && dot[1] == 0 && dot[2] == 0 && dot[3] == 0) {
					printf("rectangle\n");
				} else {
					printf("other\n");
				}
				break;
			}
		}
	}
}
