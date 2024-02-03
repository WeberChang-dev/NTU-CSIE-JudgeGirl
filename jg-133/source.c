#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string_count {
        char seen[80];
        int count;
};

int cmp(const void *a, const void *b) {
    struct string_count A = *(struct string_count *)a;
    struct string_count B = *(struct string_count *)b;
    if (A.count == B.count) {
        return strcmp(A.seen, B.seen);
    } else {
        return A.count - B.count;
    }
}

int size(struct string_count strings[]) {
    int i = 0;
    for (i; strings[i].count != 0; i++);
    return i;
}

int compare_and_add(char *string, struct string_count strings[]) {
    int n = size(strings);
    for (int i = 0; i < n; i++) {
        if (!strcmp(strings[i].seen, string)) {
            strings[i].count++;
            return 1;
        }
    }
    strings[n].count = 1;
    strcpy(strings[n].seen, string);
    return 0;
}

void sort(struct string_count strings[]) {
    qsort(strings, size(strings), sizeof(struct string_count), cmp);
}

void print(struct string_count strings[]) {
    int n = size(strings);
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", strings[i].count, strings[i].seen);
    }
}