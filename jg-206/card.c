#include <stdio.h>
#include "card.h"

void shuffle(int *deck[]) {
    int n = 0, m, *ans[10000];
    for (int i = 0; deck[i] != NULL; i++) n++;
    m = n / 2 + n % 2;
    for (int i = 0, j = 0; j < n; j += 2, i++) ans[j] = deck[i];
    for (int i = m, j = 1; j < n; j += 2, i++) ans[j] = deck[i];
    for (int i = 0; i < n; i++) deck[i] = ans[i];
}

void print(int *deck[]) {
    int i = 0;
    while (deck[i] != NULL) {
        printf("%d ", *deck[i]);
        i++;
    }
}