#include <stdio.h>
#define MAXN 100005

void mergeSort(int arr[MAXN], int left, int right, int tmp[MAXN]) {
    if (left + 1 >= right) {
        printf("%d\n", arr[left]);
        return;
    }
    for (int i = left; i < right; i++) printf("%d ", arr[i]);
    printf("\n");
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, tmp);
    mergeSort(arr, mid, right, tmp);
    for (int i = left, j = mid, k = 0; i < mid || j < right; k++) {
        if (i == mid || (j < right && arr[i] > arr[j])) {
            tmp[k] = arr[j];
            printf("%d ", arr[j]);
            j++;
        } else {
            tmp[k] = arr[i];
            printf("%d ", arr[i]);
            i++;
        }
    }
    printf("\n");
    for (int i = left; i < right; i++) arr[i] = tmp[i - left];
}

int main() {
    int input, n = 0, arr[MAXN], tmp[MAXN];
    while (scanf("%d", &input) != EOF) {
        arr[n++] = input;
    }
    mergeSort(arr, 0, n, tmp);
}