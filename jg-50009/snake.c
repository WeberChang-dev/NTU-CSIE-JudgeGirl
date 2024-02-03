int snake(int *ptr, int *row, int *column) {
    int n, c, r;
    for (int i = 1; 1; i++) {
        if (ptr[i] == 0) {
            n = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ptr[i] != i) {
            c = i;
            break;
        }
        if (i == n - 1) c = n;
    }
    r = n / c;
    int arr[r + 5][c + 5], num = 0, index = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++, num++) {
            arr[i][j] = num;
        }
    }
    for (int i = 0; i < r; i++) {
        if (i % 2) {
            for (int j = c - 1; j >= 0; j--, index++) {
                if (arr[i][j] != ptr[index]) {
                    *row = i;
                    *column = j;
                    return 0;
                }
            }
        } else {
            for (int j = 0; j < c; j++, index++) {
                if (arr[i][j] != ptr[index]) {
                    *row = i;
                    *column = j;
                    return 0;
                }
            }
        }
    }
    *row = r;
    *column = c;
    return 1; 
}