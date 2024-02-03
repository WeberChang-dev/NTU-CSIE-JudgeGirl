#include <stdio.h>
#define MAXH 505

void rookAttack(int x, int y, int arr[MAXH][MAXH]) {
    for (int i = x + 1; arr[i][y]; i++) arr[i][y] = 0;
    for (int i = x - 1; arr[i][y]; i--) arr[i][y] = 0;
    for (int i = y + 1; arr[x][i]; i++) arr[x][i] = 0;
    for (int i = y - 1; arr[x][i]; i--) arr[x][i] = 0;
}

void bishopAttack(int x, int y, int arr[MAXH][MAXH]) {
    for (int i = x + 1, j = y + 1; arr[i][j]; i++, j++) arr[i][j] = 0;
    for (int i = x - 1, j = y - 1; arr[i][j]; i--, j--) arr[i][j] = 0;
    for (int i = x + 1, j = y - 1; arr[i][j]; i++, j--) arr[i][j] = 0;
    for (int i = x - 1, j = y + 1; arr[i][j]; i--, j++) arr[i][j] = 0;
}

int main() {
    int h, w, arr[MAXH][MAXH] = {}, x, y, type;
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            arr[i][j] = 1;
        }
    }
    while (scanf("%d%d%d", &type, &y, &x) != EOF) {
        x++; y++;
        if (type == 1) {
            rookAttack(x, y, arr);
            bishopAttack(x, y, arr);
        } else if (type == 2) {
            bishopAttack(x, y, arr);
        } else if (type == 3) {
            rookAttack(x, y, arr);
        }
        arr[x][y] = 0;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            printf("%d ", !arr[i][j]);
        }
        printf("\n");
    }
}