#include <stdio.h>
#include <string.h>
#include <ctype.h>

int findUser(int n, char user[33], char users[33][33]) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(users[i], user)) {
            return i;
        }
    }
    return -1;
}

int isNum(char str[33]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void abortInstruction() {
    char str[33];
    while (1) {
        scanf("%s", str);
        if (isNum(str)) {
            return;
        }
    }
}

int findOP(char op[33], char *ops[4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j + strlen(ops[i]) <= strlen(op); j++) {
            if (!strncmp(op + j, ops[i], strlen(ops[i]))) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    int n, balance[33] = {}, money;
    char users[33][33], user1[33], user2[33], op[33], *ops[4] = {"earns", "spends", "gives", "becomes"};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", users[i], &balance[i]);
    }
    while (scanf("%s", user1) != EOF) {
        int userIndex = findUser(n, user1, users);
        if (userIndex == -1) {
            abortInstruction();
            continue;
        }
        scanf("%s", op, ops);
        int opType = findOP(op, ops);
        if (opType == -1) {
            abortInstruction();
            continue;
        }
        else if (opType == 0) {
            scanf("%d", &money);
            balance[userIndex] += money;
        } else if (opType == 1) {
            scanf("%d", &money);
            if (balance[userIndex] >= money) balance[userIndex] -= money;
        } else if (opType == 2) {
            scanf("%s", user2);
            int user2Index = findUser(n, user2, users);
            if (user2Index == -1) abortInstruction();
            else {
                scanf("%d", &money);
                if (balance[userIndex] >= money) {
                    balance[user2Index] += money;
                    balance[userIndex] -= money;
                }
            }
        } else {
            scanf("%d", &money);
            balance[userIndex] = money;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", users[i], balance[i]);
    }
}