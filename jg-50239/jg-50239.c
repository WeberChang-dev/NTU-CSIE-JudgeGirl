#include <stdio.h>
#include <string.h>
int main() {
    int n, m, pos;
    char A[2005] = { '\0' }, str[55];
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%s%d", str, &pos);
        for (int i = 0; str[i] != '\0' && pos + i < n; i++) {
            if (A[i + pos] == '\0') A[i + pos] = str[i];
            else A[i + pos] = (A[i + pos] + str[i]) / 2; 
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] == '\0') printf(" ");
        else printf("%c", A[i]);
    }
}