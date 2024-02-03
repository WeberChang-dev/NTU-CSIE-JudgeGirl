#include <stdio.h>
int main() {
    int x, i = 0, prevMV1 = -1, prevMV2 = -1, prev1 = -1, prev2 = -1, ans = 0, ansLeft = 0, ansFirst = 0;
    while (scanf("%d", &x) != EOF) {
        #ifdef DEBUG
            printf("%d %d\n", prevMV1, prevMV2);
        #endif
        if (prev1 == -1) {
            prev1 = x;
            prevMV1 = i;
        } else if (prev2 == -1) {
            prev2 = prev1;
            prev1 = x;
        } else {
            if ((prev1 < prev2 && prev1 < x) || (prev1 > prev2 && prev1 > x)) {
                if (prevMV1 == -1) prevMV1 = i - 1;
                else if (prevMV2 == -1) {
                    prevMV2 = prevMV1;
                    prevMV1 = i - 1;
                } else {
                    if ((ans < i - 1 - prevMV2 + 1) || (ans == i - 1 - prevMV2 + 1 && ansLeft < prevMV1 - prevMV2)) {
                        ans = i - 1 - prevMV2 + 1;
                        ansLeft = prevMV1 - prevMV2;
                        ansFirst = prevMV2 + 1;
                    }
                    prevMV2 = prevMV1;
                    prevMV1 = i - 1 ;
                }
            }
            prev2 = prev1; 
            prev1 = x;
        }
        i++;
    }
    if (prevMV1 == -1) prevMV1 = i - 1;
    else if (prevMV2 == -1) {
        prevMV2 = prevMV1;
        prevMV1 = i - 1;
    } else {
        if ((ans < i - 1 - prevMV2 + 1) || (ans == i - 1 - prevMV2 + 1 && ansLeft < prevMV1 - prevMV2)) {
            ans = i - 1 - prevMV2 + 1;
            ansLeft = prevMV1 - prevMV2;
            ansFirst = prevMV2 + 1;
        }
        prevMV2 = prevMV1;
        prevMV1 = i - 1;
    }
    if (ans == 0) printf("0");
    else printf("%d %d", ans, ansFirst);
}