#include <stdio.h>
#define ll long long
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : -(a))

ll overlap(ll rect1[2][2], ll rect2[2][2]) {
    if (rect1[0][0] >= rect2[1][0] || rect2[0][0] >= rect1[1][0]) return 0;
    if (rect1[0][1] >= rect2[1][1] || rect2[0][1] >= rect1[1][1]) return 0;
    return (min(rect1[1][0], rect2[1][0]) - max(rect1[0][0], rect2[0][0])) * 
           (min(rect1[1][1], rect2[1][1]) - max(rect1[0][1], rect2[0][1]));
}

void input(ll points[3][2][2]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%lld%lld", &points[i][j][0], &points[i][j][1]);
        }
    }
}

int main() {
    ll points[3][2][2], ans = 0, overlapCnt = 0;
    input(points);
    for (int i = 0; i < 3; i++) 
        ans += (points[i][1][0] - points[i][0][0]) * (points[i][1][1] - points[i][0][1]);
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            ans -= overlap(points[i], points[j]);
            #ifdef DEBUG
                printf("%lld ", overlap(points[i], points[j]));
            #endif
            if (overlap(points[i], points[j])) overlapCnt++;
        }
    }
    if (overlapCnt == 3) {
        ll overlapRect[2][2] = {{max(points[0][0][0], points[1][0][0]), max(points[0][0][1], points[1][0][1])}, 
                                {min(points[0][1][0], points[1][1][0]), min(points[0][1][1], points[1][1][1])}
        };
        #ifdef DEBUG
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    printf("%lld ", overlapRect[i][j]);
                }
            }
        #endif
        ans += overlap(overlapRect, points[2]);
        #ifdef DEBUG
            printf("%lld", overlap(overlapRect, points[2]));
        #endif
    }
    printf("%lld", ans);
}