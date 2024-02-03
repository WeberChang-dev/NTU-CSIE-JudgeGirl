#include <stdio.h>
#include <string.h>
int main() {
    int m, ptr = 0, cnt = 0;
    char words[130][260];
    scanf("%d", &m);
    while (scanf("%s", words[ptr]) != EOF) {
        cnt += strlen(words[ptr]);
        ptr++;
        if (cnt + ptr - 1 > m) {
            ptr--;
            cnt -= strlen(words[ptr]);
            if (ptr == 1) {
                printf("%s", words[0]);
                for (int i = 0; i < m - cnt; i++) printf(" ");
            } else {
                int mod = (m - cnt) % (ptr - 1);
                for (int i = 0; i < ptr; i++) {
                    printf("%s", words[i]);
                    if (i == ptr - 1) continue;
                    for (int j = 0; j < ((i < mod) ? (m - cnt) / (ptr - 1) + 1 : (m - cnt) / (ptr - 1)); j++) {
                        printf(" ");
                    }
                }
            }
            printf("\n");
            strcpy(words[0], words[ptr]);
            cnt = strlen(words[ptr]);
            ptr = 1;
        }
    }
    if (ptr != 0) {
        if (ptr == 1) {
            printf("%s", words[0]);
            for (int i = 0; i < m - cnt; i++) printf(" ");
        } else {
            int mod = (m - cnt) % (ptr - 1);
            for (int i = 0; i < ptr; i++) {
                printf("%s", words[i]);
                if (i == ptr - 1) continue;
                for (int j = 0; j < ((i < mod) ? (m - cnt) / (ptr - 1) + 1 : (m - cnt) / (ptr - 1)); j++) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}