#include <stdio.h>
#include <stdbool.h>

bool color(int n, int c, int p, int countries[25], int edges[25][25]) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (edges[p][i] && countries[i] == countries[p]) return false;
        if (edges[p][i] && !countries[i]) {
            for (int j = 1; j <= c; j++) {
                countries[i] = j;
                bool smolFlag = color(n, c, i, countries, edges);
                if (smolFlag) break;
                countries[i] = 0;
                if (j == c) return false;
            }
        }
    }
    return flag;
}

bool full(int n, int countries[25]) {
    for (int i = 0; i < n; i++) {
        if (!countries[i]) {
            return false;
        }
    }
    return true;
}

void printCountries(int n, int countries[25]) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", countries[i]);
    }
}

int main() {
    int n, c, p, countries[25] = {}, edge[25][25] = {};
    scanf("%d%d%d", &n, &c, &p);
    for (int i = 0; i < p; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a][b] = edge[b][a] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!countries[i]) {
            for (int j = 1; j <= c; j++) {
                countries[i] = j;
                if (color(n, c, i, countries, edge)) break;
                countries[i] = 0;
            }
            if (countries[i] == 0) break;
        }
    }
    if (full(n, countries)) printCountries(n, countries);
    else printf("no solution.\n");
}