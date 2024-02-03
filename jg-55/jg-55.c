#include<stdio.h>
int main() {
    int n, m, x1, y1, e1, n1, f1, x2, y2, e2, n2, f2, cnt1 = 0, cnt2 = 0, bang = 0;
    char dir1 = 'n', dir2 = 'e';
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &m, &n, &x1, &y1, &e1, &n1, &f1, &x2, &y2, &e2, &n2, &f2);
    for (int t = 1; f1 || f2; t++) {
        if (dir1 == 'n' && f1) {
            y1 = (y1 + 1) % n;
            cnt1++;
            f1--;
            if (cnt1 == n1) {
                cnt1 = 0;
                dir1 = 'e';
            }
        } else if (dir1 == 'e' && f1) {
            x1 = (x1 + 1) % m;
            cnt1++;
            f1--;
            if (cnt1 == e1) {
                cnt1 = 0;
                dir1 = 'n';
            }
        }
        if (dir2 == 'n' && f2) {
            y2 = (y2 + 1) % n;
            cnt2++;
            f2--;
            if (cnt2 == n2) {
                cnt2 = 0;
                dir2 = 'e';
            }
        } else if (dir2 == 'e' && f2) {
            x2 = (x2 + 1) % m;
            cnt2++;
            f2--;
            if (cnt2 == e2) {
                cnt2 = 0;
                dir2 = 'n';
            }
        }
        if (x1 == x2 && y1 == y2) {
            printf("robots explode at time %d", t);
            bang = 1;
            break;
        }
    }
    if (!bang) printf("robots will not explode");
}