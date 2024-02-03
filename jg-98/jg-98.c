#include <stdio.h>
#include <string.h>
int main() {
    int n, m, indexA, indexB, cnt[105];
    char foods[105][65], ingredients[105][15][65], a[65], b[65];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", foods[i], &cnt[i]);
        for (int j = 0; j < cnt[i]; j++) {
            scanf("%s", ingredients[i][j]);
        }
    }
    scanf("%d", &m);
    while (m--) {
        int ans[15], ptr = 0;
        scanf("%s%s", a, b);
        for (int i = 0; i < n; i++) {
            if (strcmp(a, foods[i]) == 0) indexA = i;
            if (strcmp(b, foods[i]) == 0) indexB = i;
        }
        for (int i = 0; i < cnt[indexA]; i++) {
            for (int j = 0; j < cnt[indexB]; j++) {
                if (!strcmp(ingredients[indexA][i], ingredients[indexB][j])) {
                    ans[ptr++] = i;
                }
            }
        }
        for (int i = 0; i < ptr; i++) {
            for (int j = 1; j < ptr; j++) {
                if (strcmp(ingredients[indexA][ans[j - 1]], ingredients[indexA][ans[j]]) > 0) {
                    int tmp = ans[j - 1];
                    ans[j - 1] = ans[j];
                    ans[j] = tmp;
                }
            }
        }
        for (int i = 0; i < ptr; i++) {
            printf(((i != ptr - 1) ? "%s " : "%s"), ingredients[indexA][ans[i]]);
        }
        if (!ptr) printf("nothing");
        if (m != 0) printf("\n");
    }
}