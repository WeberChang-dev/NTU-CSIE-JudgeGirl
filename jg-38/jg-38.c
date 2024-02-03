#include <stdio.h>
#include <stdbool.h>

bool makeLotion(int D, long long curPower, int aU, int bU, int cU, int aP, int bP, int cP) {
    if (curPower > D) return false;
    if (curPower == D) return true;
    if (aU) {
        if (makeLotion(D, curPower + aP, aU - 1, bU, cU, aP, bP, cP)) {
            return true;
        }
    }
    if (bU) {
        if (makeLotion(D, curPower + bP, aU, bU - 1, cU, aP, bP, cP)) {
            return true;
        }
    }
    if (cU) {
        if (makeLotion(D, curPower + cP, aU, bU, cU - 1, aP, bP, cP)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, D, aU, bU, cU, aP, bP, cP;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d%d%d%d%d", &D, &aU, &bU, &cU, &aP, &bP, &cP);
        if (makeLotion(D, 0, aU, bU, cU, aP, bP, cP)) printf("yes\n");
        else printf("no\n");
    }
}