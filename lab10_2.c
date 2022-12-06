#include "stdio.h"
#define ull unsigned long long

ull process(int n, int level) {
//    printf("lvl: %3d\tF(%d, %d)\n", level, n, level);
    ull value;
    if (n == 1) value = 1;
    else if (n == 2) value = 3;
    else value  = process(n - 1, level + 1) + process(n - 2, level + 1);
//    printf("lvl: %3d\tresult: %d\n", level, value);
    return value;
}

int main(void) {
    int k;
    scanf("%d", &k);
    printf("%llu", process(k, 0));
}
