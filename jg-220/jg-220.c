#include <stdio.h>
int main() {
    char ch;
    int lines = 0, prevComma = 0, prevSpace = 0;
    while (scanf("%c", &ch) != EOF) {
        if (ch == '.') {
            prevComma = 1;
            prevSpace = 0;
        } else if (ch == '\n') {
            lines += (prevComma && !prevSpace);
            prevComma = prevSpace = 0;
        } else if (ch == ' ') {
            if (prevSpace && prevComma) {
                lines++;
                prevComma = 0;
                prevSpace = 0;
            } else {
                prevSpace = 1;
            }
        } else {
            prevComma = 0;
            prevSpace = 0;
        }
    }
    printf("%d", lines + prevComma);
}