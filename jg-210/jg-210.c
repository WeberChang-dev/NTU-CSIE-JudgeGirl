#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char lastname[85], firstname[85], ID[85];
    int salary, age;
} Person;

int find(char *field[5], char str[85]) {
    for (int i = 0; i < 5; i++) {
        if (!strcmp(field[i], str)) {
            return i;
        }
    }
    return -1;
}

char* selectStr(Person *p, int i) {
    if (i == 0) return p -> lastname;
    else if (i == 1) return p -> firstname;
    else return p -> ID;
}

int selectInt(Person p, int i) {
    if (i == 3) return p.salary;
    else return p.age;
}

void outputPerson(char *field[5], char selectField[10][10], Person *p, int index) {
    for (int j = 0; j < index; j++) {
        if (find(field, selectField[j]) < 3 && selectField[j]) {
            printf("%s ", selectStr(p, find(field, selectField[j])));
        } else if (find(field, selectField[j]) >= 3 && selectField[j]) {
            printf("%d ", selectInt(*p, find(field, selectField[j])));
        }
    }
    printf("\n");
}

int main() {
    Person SQL[55];
    int n, m, num, selectCondition, selectCompare, fieldIndex;
    bool ok, isCondition;
    char input[200], *compare[5] = {"==", "!=", "==", ">", "<"}, *field[5] = {"lastname", "firstname", "ID", "salary", "age"}, selectField[10][10], *str;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s%s%d%d", &(SQL[i].lastname), &(SQL[i].firstname), &(SQL[i].ID), &(SQL[i].salary), &(SQL[i].age));
    }
    scanf("%d", &m);

    while (fgets(input, 200, stdin) != NULL) {
        isCondition = false;
        fieldIndex = selectCondition = selectCompare = 0;
        str = strtok(input, " \n");
        while (str != NULL) {
            if (strcmp(str, "select")) {
                if (!strcmp(str, "where")) {
                    isCondition = true;
                } else if (isCondition) {
                    if (find(field, str) != -1) {
                        selectCondition = find(field, str);
                    } else if (find(compare, str) != -1) {
                        selectCompare = find(compare, str);
                    } else {
                        if (selectCondition == 0 || selectCondition == 1 || selectCondition == 2) {
                            for (int i = 0; i < n; i++) {
                                ok = false;
                                if (selectCompare == 0)
                                    ok = !strcmp(selectStr(&(SQL[i]), selectCondition), str);
                                else 
                                    ok = strcmp(selectStr(&(SQL[i]), selectCondition), str);
                                if (!ok) continue;
                                outputPerson(field, selectField, &(SQL[i]), fieldIndex);
                            }
                        } else {
                            num = atoi(str);
                            for (int i = 0; i < n; i++) {
                                ok = false;
                                if (selectCompare == 0)
                                    ok = num == selectInt(SQL[i], selectCondition);
                                else if (selectCompare == 3)
                                    ok = num < selectInt(SQL[i], selectCondition);
                                else
                                    ok = num > selectInt(SQL[i], selectCondition);
                                if (!ok) continue;
                                outputPerson(field, selectField, &(SQL[i]), fieldIndex);
                            }
                        }
                    }
                } else {
                    strcpy(selectField[fieldIndex++], str);
                }
            }
            str = strtok(NULL, " \n");
        }
    }
}