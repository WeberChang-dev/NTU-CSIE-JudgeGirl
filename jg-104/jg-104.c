#include <stdio.h>
#include <stdbool.h>

bool materialComposition(int D[3], int E[3], int F[3], int supplyA, int supplyB, int supplyC) {
    if (supplyA < 0 || supplyB < 0 || supplyC < 0) return false;
    if (supplyA == 0 && supplyB == 0 && supplyC == 0) return true;
    if (materialComposition(D, E, F, supplyA - D[0], supplyB - D[1], supplyC - D[2])) return true;
    if (materialComposition(D, E, F, supplyA - E[0], supplyB - E[1], supplyC - E[2])) return true;
    if (materialComposition(D, E, F, supplyA - F[0], supplyB - F[1], supplyC - F[2])) return true;
    return false;
}

void solve(int n, int D[3], int E[3], int F[3], int supply[3]) {
    if (n == 0) return;
    scanf("%d%d%d", &supply[0], &supply[1], &supply[2]);
    if (materialComposition(D, E, F, supply[0], supply[1], supply[2])) printf("yes\n");
    else printf("no\n");
    solve(n - 1, D, E, F, supply);
}

int main() {
    int n, D[3], E[3], F[3], supply[3];
    scanf("%d%d%d", &D[0], &D[1], &D[2]);
    scanf("%d%d%d", &E[0], &E[1], &E[2]);
    scanf("%d%d%d", &F[0], &F[1], &F[2]);
    scanf("%d", &n);
    solve(n, D, E, F, supply);
}