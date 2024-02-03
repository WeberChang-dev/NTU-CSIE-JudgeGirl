#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ((a) < (b) ? (a) : (b)) 
#define max(a,b) ((a) > (b) ? (a) : (b)) 
int main() {
    int p[4][2];
    for (int i = 0; i < 4; i++) {
        scanf("%d%d", &p[i][0], &p[i][1]);
    }
    printf("%d\n%d", 
          (2 * (p[2][0] - p[0][0] + p[2][1] - p[0][1])),
          (p[2][0] - p[0][0]) * (p[2][1] - p[0][1]) - (p[2][0] - p[1][0]) * (p[1][1] - p[0][1]) - (p[3][0] - p[0][0]) * (p[2][1] - p[3][1])
    );
}