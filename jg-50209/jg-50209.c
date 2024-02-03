#include <stdio.h>
#include <string.h>
int main() {
    char *board[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"}, ch;
    int dir[6][2] = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}}, move, x, y;
    scanf("%c", &ch);
    for (int i = 0; i < 3; i++) {
        if (strchr(board[i], ch) != NULL) {
            x = i;
            y = strchr(board[i], ch) - board[i]; 
        }
    }
    printf("%c\n", ch);
    while (scanf("%d", &move) != EOF) {
        int newX = dir[move][0] + x, newY = dir[move][1] + y;
        if (newX < 0 || newX > 2 || newY < 0 || newY >= strlen(board[newX])) continue;
        x = newX; y = newY;
        printf("%c\n", board[newX][newY]);
    }
}