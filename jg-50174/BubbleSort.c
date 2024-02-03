#include <stdint.h>

void BubbleSort(uint64_t input, uint64_t output[63]) {
    int prevBit, nextBit;
    for (int i = 0; i < 63; i++) {
        for (int j = 63; j > 0; j--) {
            prevBit = (input & ((uint64_t)(1) << j)) != 0;
            nextBit = (input & ((uint64_t)(1) << (j - 1))) != 0;
            if (prevBit == 1 && nextBit == 0) {
                input -= ((uint64_t)(1) << j);
                input += ((uint64_t)(1) << (j - 1));
            }
        }
        output[i] = input;
    }
}