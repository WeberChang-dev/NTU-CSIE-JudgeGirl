#include<stdio.h>

int abs(int x) {
	return ((x < 0) ? -x : x);
}

int main() {
	int n, m, x, y, park[15][3], ans[15] = {};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &park[i][0], &park[i][1], &park[i][2]);
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		int preX = 10005, preY = 10005, pos = 0, newDis, minDis = 40005;
		for (int i = 0; i < n; i++) {
			if (!park[i][2]) continue;
			newDis = abs(park[i][0] - x) + abs(park[i][1] - y);
			if (newDis < minDis) {
				pos = i;
				minDis = newDis;
				preX = park[i][0];
				preY = park[i][1];
			} else if (newDis == minDis) {
				if (park[i][0] < preX) {	
					pos = i;
					minDis = newDis;
					preX = park[i][0];
					preY = park[i][1];
				} else if (park[i][0] == preX && park[i][1] < preY) {
					pos = i;
					minDis = newDis;
					preX = park[i][0];
					preY = park[i][1];
				}
			} 		
		}
		ans[pos]++;
		park[pos][2]--;
	}
	for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
}
