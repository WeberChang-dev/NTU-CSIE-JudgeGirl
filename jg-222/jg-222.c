#include <stdio.h>

int hasEOF = 0;

int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}

int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

unsigned long long decodeBook(unsigned long long shelf, int pos) {
    unsigned long long ret = 0;
    for (int i = 0; i < 8; i++) {
        ret |= ((shelf & (((long long)1) << (pos + i))) >> pos);
    }
    return ret;
}

int main() {
    int x;
    unsigned long long shelf = 0;
    while (ReadInt(&x)) {
        int found = 0;
        for (int i = 0; i <= 56; i += 8) {
            if (x == decodeBook(shelf, i)) {
                shelf = ((i == 56) ? 0 : ((shelf >> (i + 8)) << (i + 8))) + ((i == 0) ? 0 : ((shelf << (64 - i)) >> (56 - i))) + x;
                found = 1; 
                break;
            }
        }
        if (!found) shelf = (shelf << 8) + x;
    }    
    for (int i = 56; i >= 0; i -= 8) {
        printf(i == 0 ? "%d" : "%d ", decodeBook(shelf, i));
    }
    return 0;
}