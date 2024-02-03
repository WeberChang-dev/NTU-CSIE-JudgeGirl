#include <stdio.h>

int nextSeat(int arr[3], int n, int car, int row, int seat) {
    if (car <= n && row <= 20 && seat < 5) {
        arr[0] = car;
        arr[1] = row;
        arr[2] = seat + 1;
        return 1;
    } else if (car <= n && row < 20) {
        arr[0] = car;
        arr[1] = row + 1;
        arr[2] = 1;
        return 1;
    } else if (car < n) {
        arr[0] = car + 1;
        arr[1] = 1;
        arr[2] = 1;
        return 1;
    }
    return -1;
}

int main() {
    int n, empty[20 * 5 * 1000][3], r, frontPtr = 0, endPtr = 0, overflow = 0;
    empty[0][0] = empty[0][1] = empty[0][2] = 1;
    scanf("%d", &n);
    while (scanf("%d", &r) != -1) {
        if (r == 1) {
            printf("%d %d %d\n", empty[frontPtr][0], empty[frontPtr][1], empty[frontPtr][2]);
            if (frontPtr == endPtr) {
                int newSeat[3];
                if (!overflow && nextSeat(newSeat, n, empty[frontPtr][0], empty[frontPtr][1], empty[frontPtr][2]) == 1) {
                    for (int i = 0; i < 3; i++) empty[frontPtr + 1][i] = newSeat[i];
                }
                frontPtr++; endPtr++;
            } else {
                frontPtr++;
            }
        } else {
            if (empty[endPtr][2] == 3 || empty[endPtr][2] == 5) {
                int newSeat[3], result = nextSeat(newSeat, n, empty[endPtr][0], empty[endPtr][1], empty[endPtr][2]);
                if (overflow || result == -1) {
                    printf("%d %d %d %d %d %d\n", empty[frontPtr][0], empty[frontPtr][1], empty[frontPtr][2], empty[frontPtr + 1][0], empty[frontPtr + 1][1], empty[frontPtr][2]);
                    frontPtr += 2;
                } else {
                    printf("%d %d %d %d %d %d\n", newSeat[0], newSeat[1], newSeat[2], newSeat[0], newSeat[1], newSeat[2] + 1);
                    if (!overflow && nextSeat(newSeat, n, newSeat[0], newSeat[1], newSeat[2] + 1) == 1) {
                        endPtr++; 
                        for (int i = 0; i < 3; i++) empty[endPtr][i] = newSeat[i];
                    } else {
                        overflow = 1;
                    }
                }
            } else {
                printf("%d %d %d %d %d %d\n", empty[endPtr][0], empty[endPtr][1], empty[endPtr][2], empty[endPtr][0], empty[endPtr][1], empty[endPtr][2] + 1);
                int newSeat[3];
                if (!overflow && nextSeat(newSeat, n, empty[endPtr][0], empty[endPtr][1], empty[endPtr][2] + 1) == 1) {
                    for (int i = 0; i < 3; i++) empty[endPtr][i] = newSeat[i];
                }
            }
        }
    }
} 