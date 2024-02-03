#include "value.h"
#define GOLD 79
#define SILVER 47
#define COPPER 29
#define LEAD 82
#define IRON 26
#define TITANIUM 22

int unitPrice(int x) {
    switch (x) {
        case GOLD:
            return 30;
        case SILVER:
            return 10;
        case COPPER:
            return 4;
        case LEAD:
            return 5;
        case IRON:
            return 3;
        case TITANIUM:
            return 9;
        default:
            return -1;
    }
}

int cube(int x) {
    return x * x * x;
}

int _gcd(int x, int y) {
    if (!y) return x;
    return _gcd(y, x % y);
}

int value(int type, int width, int height, int length) {
    if (unitPrice(type) == -1) return -1;
    if (width <= 0 || height <= 0 || length <= 0) return -2;
    return unitPrice(type) * width * height * length * cube(_gcd(_gcd(width, height), length));
}