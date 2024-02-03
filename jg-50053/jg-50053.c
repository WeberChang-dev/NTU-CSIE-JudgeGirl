#include <stdio.h>
#include <string.h>

int find(char a[50], char A[100][50], int n) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(a, A[i])) {
            return i;
        }
    }
    return -1;
}

int main() {
    int m, bookToAuthor[100], end = 0, sum[100] = {}, sell, ans = 0;
    char authors[100][50], books[100][50], author[50], book[50], ansStr[50];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s%s", author, books[i]);
        int index = find(author, authors, end);
        if (index == -1) {
            strcpy(authors[end], author);
            index = end;
            end++;
        }
        bookToAuthor[i] = index;
    }
    for (int i = 0; i < m; i++) {
        scanf("%s%d", book, &sell);
        sum[bookToAuthor[find(book, books, m)]] +=  sell;
    }
    for (int i = 0; i < end; i++) {
        if (sum[i] > ans || (sum[i] == ans && strcmp(authors[i], ansStr) < 0)) {
            ans = sum[i];
            strcpy(ansStr, authors[i]);
        }
    }
    printf("%s %d", ansStr, ans);
}