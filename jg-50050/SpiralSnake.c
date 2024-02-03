void SpiralSnake(int N, int *snake, int *result) {
    int arr[1000][1000], index = 0, x = N / 2, y = N / 2;
    arr[x][y] = snake[index];
    index++;
    for (int i = 2; index < N * N; i += 2) {
        y--;
        for (int j = 0; j < i; j++) {
            arr[x][y] = snake[index];
            x--, index++;
        }
        x++, y++;
        for (int j = 0; j < i; j++) {
            arr[x][y] = snake[index];
            y++, index++;
        }
        y--, x++;
        for (int j = 0; j < i; j++) {
            arr[x][y] = snake[index];
            x++, index++;
        }
        x--, y--;
        for (int j = 0; j < i; j++) {
            arr[x][y] = snake[index];
            y--, index++;
        }
        y++;
    }
    index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++, index++) {
            result[index] = arr[i][j];
        }
    }
}