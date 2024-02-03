#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
} Employee;

int findEmployeeWithName(Employee company[35], char first_name[32], char last_name[32], int n) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(first_name, company[i].first_name) && !strcmp(last_name, company[i].last_name)) {
            return i;
        }
    }
}

int findEmployeeWithID(Employee company[35], int id, int n) {
    for (int i = 0; i < n; i++) {
        if (company[i].id == id) {
            return i;
        }
    }
}

int findBoss(Employee company[35], uint32_t boss, int id, int n) {
    int index = findEmployeeWithID(company, id, n);
    if (company[index].boss_id == id) {
        return boss | (uint32_t)(1) << index;
    } else {
        return findBoss(company, boss | (uint32_t)(1) << index, company[index].boss_id, n);
    }
}

int main() {
    Employee company[35];
    int n, m, aIndex, bIndex;
    uint32_t aBoss = 0, bBoss = 0;
    char aFirst[32], aLast[32], bFirst[32], bLast[32];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%s%s%d", &company[i].id, &company[i].first_name, &company[i].last_name, &company[i].boss_id);
    }
    scanf("%d", &m);
    while (m--) {
        aBoss = bBoss = 0;
        scanf("%s%s%s%s", aFirst, aLast, bFirst, bLast);
        aIndex = findEmployeeWithName(company, aFirst, aLast, n);
        bIndex = findEmployeeWithName(company, bFirst, bLast, n);
        aBoss = findBoss(company, aBoss, company[aIndex].boss_id, n);
        bBoss = findBoss(company, bBoss, company[bIndex].boss_id, n);
        if (aBoss & (uint32_t)(1) << bIndex) {
            printf("subordinate\n");
        } else if (bBoss & (uint32_t)(1) << aIndex) {
            printf("supervisor\n");
        } else if (bBoss & aBoss) {
            printf("colleague\n");
        } else {
            printf("unrelated\n");
        }
    }
}