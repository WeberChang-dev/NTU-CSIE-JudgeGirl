#include<stdio.h>

int over(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            return arr[i][0];
        }
        if (arr[0][i] && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
            return arr[0][i];
        }
    }
    if (arr[0][0] && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) return arr[0][0];
    if (arr[0][2] && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) return arr[1][1];
    return 0;
}

int main() {
    int n, game[3][3] = {}, x, y;
    char turn = 'b';
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &x, &y);
        if ((x > 2 || x < 0) || (y > 2 || y < 0)) continue;
        if (game[x][y]) continue;
        if (turn == 'b') {
            game[x][y] = -1;
            turn = 'w';
        } else {
            game[x][y] = 1;
            turn = 'b';
        }
        if (over(game) == 1) {
            printf("White wins.");
            break;
        } 
        if (over(game) == -1) {
            printf("Black wins.");
            break;
        }
    }
    if (!over(game)) printf("There is a draw.");
}