#include "employee.h"
#include <stdint.h>

void findBoss(Employee *boss[32], Employee *ptr, int *n) {
    boss[*n] = ptr;
    *n += 1;
    if (ptr -> boss != ptr) {
        findBoss(boss, ptr -> boss, n);
    }
}

int find(Employee *boss[32], Employee *ptr, int n) {
    for (int i = 0; i < n; i++) {
        if (ptr == boss[i]) {
            return 1;
        }
    }
    return 0;
}

int sameBoss(Employee *bossA[32], Employee *bossB[32], int indexA, int indexB) {
    for (int i = 0; i < indexA; i++) {
        if (find(bossB, bossA[i], indexB)) {
            return 1;
        }
    }
    return 0;
}
 
int relation(Employee *employee1, Employee *employee2) {
    int indexA = 0, indexB = 0;
    Employee *bossA[32], *bossB[32];
    findBoss(bossA, employee1, &indexA);
    findBoss(bossB, employee2, &indexB);
    if (find(bossA, employee2, indexA)) {
        return 1;
    } else if (find(bossB, employee1, indexB)) {
        return 2;
    } else if (sameBoss(bossA, bossB, indexA, indexB)) {
        return 3;
    } else {
        return 4;
    }
}