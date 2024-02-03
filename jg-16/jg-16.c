#include<stdio.h>
int main() {
    int n, arr[1005], odd[1005], even[1005], oddPtr = 0, evenPtr = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2) odd[oddPtr++] = arr[i];
        else even[evenPtr++] = arr[i];
    }
    printf("%d", odd[0]);
    for (int i = 1; i < oddPtr; i++) printf(" %d", odd[i]);
    printf("\n%d", even[0]);
    for (int i = 1; i < evenPtr; i++) printf(" %d", even[i]);
}