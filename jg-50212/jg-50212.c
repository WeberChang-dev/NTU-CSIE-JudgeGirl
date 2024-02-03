#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    bool isEven;
    uint32_t C;
} Bits;

Bits X(uint32_t C, int len) {
    Bits ret;
    if (len == 1) {
        ret.isEven = (C == 0);
        ret.C = C;
        return ret;
    }
    uint32_t A = C / ((uint32_t)(1) << (len / 2)), B = C % ((uint32_t)(1) << (len / 2));
    Bits ARet = X(A, len / 2), BRet = X(B, len / 2);
    ret.isEven = (ARet.isEven && BRet.isEven) || (!ARet.isEven && !BRet.isEven);
    // printf("%u %u, %u %u, %d\n", A, B, ARet.C, BRet.C, ret.isEven);
    if (ret.isEven) {
        ret.C = BRet.C + (ARet.C << (len / 2));
    } else {
        ret.C = ARet.C + (BRet.C << (len / 2));
    }
    return ret;
}

int main() {
    uint32_t C;
    scanf("%u", &C);
    Bits ans = X(C, 32);
    printf("%u", ans.C);
}