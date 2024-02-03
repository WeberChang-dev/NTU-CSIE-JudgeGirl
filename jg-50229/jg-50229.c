#include <stdio.h>
#define MAXK 20005

int min(int a, int b) { return ((a < b) ? a : b); }

int main() {
    int k, capacity[MAXK], water[MAXK], i, j;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) scanf("%d", &capacity[i]);
    for (int i = 0; i < k; i++) scanf("%d", &water[i]);
    while (scanf("%d%d", &i, &j) != EOF) {
        if (i == k) water[j] = capacity[j];
        else if (j == k) water[i] = 0;
        else {
            int change = min(water[i], capacity[j] - water[j]);
            water[i] -= change;
            water[j] += change;
        }
    }
    for (int i = 0; i < k; i++) printf("%d ", water[i]);
}