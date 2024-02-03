#include<stdio.h>
int main() {
    int arr[105], n, len = 0, prevLen = 0, sumLen = 0, prevPtr = 0, ansPtr1 = 0, ansPtr2 = 0, maxPtr = 0;
    while (scanf("%d", &n) != EOF)
        arr[len++] = n;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = i; k < j; k++) {
                #ifdef DEBUG
                    printf("%d %d %d\n", i, k, j);
                #endif
                int isPalindrome = 1;
                for (int l = 0; l + i <= k; l++) {
                    if (arr[l + i] != arr[k - l]) {
                        isPalindrome = 0;
                        break;
                    }
                }
                if (!isPalindrome) {
                    continue;;
                }
                for (int l = 0; l + k + 1 <= j; l++) {
                    if (arr[l + k + 1] != arr[j - l]) {
                        isPalindrome = 0;
                        break;
                    }
                }
                if (!isPalindrome) {
                    continue;;
                }
                if (j - i > ansPtr2 - ansPtr1 || (j - i == ansPtr2 - ansPtr1 && j > ansPtr2)) {
                    ansPtr1 = i;
                    ansPtr2 = j;
                }
            }
        }
    }
    for (int i = ansPtr1; i <= ansPtr2 - 1; i++) printf("%d ", arr[i]);
    printf("%d", arr[ansPtr2]);
}