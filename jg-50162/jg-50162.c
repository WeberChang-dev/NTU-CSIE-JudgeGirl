#include <stdio.h>
#define MAXN 5000
int main() {
	int id, players[MAXN][3];
	short int back[3] = {}, head[3] = {}, cnt[3] = {};
	while (scanf("%d", &id) != EOF) {
		players[back[id % 3]][id % 3] = id;
		cnt[id % 3]++;
		back[id % 3] = (back[id % 3] + 1) % MAXN;
		if (cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 1) {
			for (int i = 0; i < 3; i++, head[0] = (head[0] + 1) % MAXN) {
				printf("%d ", players[head[0]][0]);
			} 
			printf("%d ", players[head[1]][1]);
			printf("%d\n", players[head[2]][2]);
			cnt[0] -= 3;
			cnt[1] -= 1;
			cnt[2] -= 1;
			head[1] = (head[1] + 1) % MAXN;
			head[2] = (head[2] + 1) % MAXN;
		}
	}
}
