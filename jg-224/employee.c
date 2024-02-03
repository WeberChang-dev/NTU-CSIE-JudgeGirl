#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
 
void init_storage(Employee **storage, int n) {
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage) {
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id(Employee *set, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (set[i].id == id) {
            return set + i;
        }
    }
}

Employee* find_employee_by_name(Employee *set, int n, const char *first_name, const char *last_name) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(first_name, set[i].first_name) && !strcmp(last_name, set[i].last_name)) {
            return set + i;
        }
    }
}

Employee* find_root_boss(Employee *set, int n, Employee *employee) {
    return (employee -> boss_id == employee -> id) ? 
            employee : 
            find_root_boss(set, n, find_employee_by_id(set, n, employee -> boss_id));
}

int check_relationship(Employee *set, int n, Employee *A, Employee *B) {
    int ABoss = find_root_boss(set, n, A) -> id, BBoss = find_root_boss(set, n, B) -> id;
    if (ABoss == B -> id) {
        return 1;
    } else if (BBoss == A -> id) {
        return 2;
    } else if (ABoss == BBoss) {
        int ogBBossID = B -> boss_id;
        B -> boss_id = B -> id;
        if (find_root_boss(set, n, A) -> id == B -> id) {
            B -> boss_id = ogBBossID;
            return 1;
        }
        B -> boss_id = ogBBossID;
        int ogABossID = A -> boss_id;
        A -> boss_id = A -> id;
        if (find_root_boss(set, n, B) -> id == A -> id) {
            A -> boss_id = ogABossID;
            return 2;
        }
        A -> boss_id = ogABossID;
        return 3;
    } else {
        return 4;
    }
}