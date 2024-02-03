#include <stdio.h>
int main() {
    int n, appeared[105], x;
    for (int i = 0; i < 105; i++) appeared[i] = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (appeared[x] == -1) {
            appeared[x] = i;
            printf("%d\n", i);
        }
        else {
            printf("%d %d %d\n", i, appeared[x], x);
            appeared[x] = -1;
        }
    }
}