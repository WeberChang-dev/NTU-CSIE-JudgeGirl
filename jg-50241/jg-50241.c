#include <stdio.h>
#include <stdint.h>

int main() {
    int n;
    uint64_t str;
    scanf("%d", &n);
    while (n--) {
        scanf("%llu", &str);
        for (int i = 0; i < 12; i++) {
            printf("%c", 'a' + str % 32);
            str /= 32;
        }
    }
}