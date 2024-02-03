#include <stdio.h>
int main() {
    int a, b, da[2], db[3], ansP, ansD;
    scanf("%d%d%d%d%d%d%d", &a, &b, &da[1], &da[0], &db[0], &db[1], &db[2]);
    ansD = da[a % 2];
    ansP = a;
    if (da[(a + 1) % 2] * ansP > ansD * (a + 1) ) {
        ansD = da[(a + 1) % 2];
        ansP = a + 1;
    }
    if (db[(b) % 3] * ansP > ansD * (b)) {
        ansD = db[(b) % 3];
        ansP = b;
    }
    if (db[(b + 1) % 3] * ansP > ansD * (b + 1)) {
        ansD = db[(b + 1) % 3];
        ansP = b + 1;
    } 
    if (db[(b + 2) % 3] * ansP > ansD * (b + 2)) {
        ansD = db[(b + 2) % 3];
        ansP = b + 2;
    }
    printf("%d", (ansD) ? ansP : 1);
}