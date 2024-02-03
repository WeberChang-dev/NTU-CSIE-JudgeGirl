#include<stdio.h>
int main() {
    int n, m, k, row = 0, col = 0, sum = 0;
    scanf("%d%d%d", &n, &m, &k);
    n--;
    while (1) {
    #ifdef DEBUG
        printf("%d %d\n", row, col);
    #endif
        if (row == col) {
            if (sum + m >= k) {
                printf("%d %d", row + 1, col + k - sum);
                break;
            } else {
                row++;
                sum += m;
                m--;
            }
        } else {
            if (sum + n >= k) {
                printf("%d %d", row + k - sum, col + 1);
                break;
            } else {
                col++;
                sum += n;
                n--;
            }
        }
    }
}