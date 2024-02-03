#include <stdio.h>
int main() {
    int g, h, ch, n, r, attack[3][3], use[3] = {}, b;
    scanf("%d%d%d", &r, &h, &g);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &attack[i][j]);
        }
    }
    ch = h;
    scanf("%d", &b);
    for (int i = 0; i < r; i++) {
        int attackType = -1, curAttack = -1;
        for (int j = 0; j < 3; j++) {
            if (use[j] == 0) {
                if (i > attack[j][2]) {
                    if (attack[j][0] + attack[j][1] * (i - attack[j][2]) > curAttack) {
                        attackType = j;
                        curAttack = attack[j][0] + attack[j][1] * (i - attack[j][2]);
                    }
                } else {
                    if (attack[j][0] > curAttack) {
                        attackType = j;
                        curAttack = attack[j][0];
                    }
                }
            } else if (i >= use[j]) {
                if (attack[j][0] + attack[j][1] * (i - use[j]) > curAttack) {
                    attackType = j;
                    curAttack = attack[j][0] + attack[j][1] * (i - use[j]);
                }
            }
        }
        if (curAttack < b) curAttack = b;
        else use[attackType] = i + attack[attackType][2];
        ch -= curAttack;
        printf("%d ", ch);
        if (ch <= 0) break;
        ch += g;
        if (ch > h) ch = h;
    }
}