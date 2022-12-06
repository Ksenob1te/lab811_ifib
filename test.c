#include "stdio.h"
#define ull unsigned long long

ull process(ull n, ull m) {
    if (m == n || m == 0) return 1;
    else return (process(m, n - 1) + process(m - 1, n - 1));
}

int main(void) {
    ull n, m;
    scanf("%llu%llu", &n, &m);
    if (m >= 0 && n >= m)
        printf("%llu", process(n, m));
    else
        printf("-1");
}