#include <stdio.h>
#define ll long long

void newSeq(ll *curLen, ll *curFirst, ll *prev, ll *curSum, ll *cur) {
    *curLen = 1;
    *curFirst = *cur;
    *prev = *cur;
    *curSum = *cur;
}

void prolongSeq(ll *curLen, ll *curFirst, ll *prev, ll *curSum, ll *cur, ll *dif) {
    *curLen += 1;
    *dif = *cur - *prev;
    *prev = *cur;
    *curSum += *cur;
}

void endSeq(ll *curLen, ll *curFirst, ll *prev, ll *curSum, ll *cur, ll *dif, ll *ansSum, ll *ansLen, ll *ansFirst) {
    if (
        (*ansSum < *curSum) || 
        (*ansSum == *curSum && *ansLen < *curLen) || 
        (*ansSum == *curSum && *ansLen == *curLen && *ansFirst < *curFirst)
    ) {
        *ansSum = *curSum;
        *ansFirst = *curFirst;
        *ansLen = *curLen;
    }
}

int main() {
    ll n, cur, ansSum = 0, ansLen = 0, ansFirst = 0, curSum = 0, curLen = 0, curFirst = 0, dif, prev;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &cur);
        if (curLen == 0) {
            newSeq(&curLen, &curFirst, &prev, &curSum, &cur);
        } else if (curLen == 1 || cur - prev == dif) {
            prolongSeq(&curLen, &curFirst, &prev, &curSum, &cur, &dif);
        } else if (cur - prev != dif) {
            endSeq(&curLen, &curFirst, &prev, &curSum, &cur, &dif, &ansSum, &ansLen, &ansFirst);
            newSeq(&curLen, &curFirst, &prev, &curSum, &prev);
            prolongSeq(&curLen, &curFirst, &prev, &curSum, &cur, &dif);
        }
    }
    endSeq(&curLen, &curFirst, &prev, &curSum, &cur, &dif, &ansSum, &ansLen, &ansFirst);
    printf("%lld %lld %lld", ansSum, ansLen, ansFirst);
}