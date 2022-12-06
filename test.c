#include "stdio.h"
#include "stdlib.h"
#define ull unsigned long long

ull ftod(ull pin) {
    ull din = 0;
    ull temp = 1;
    while (pin) {
        din += temp * (pin % 10);
        temp *= 5;
        pin /= 10;
    }
    return din;
}

int dtof(ull din, ull *pin) {
    *pin = 0;
    ull temp = 1;
    while (din) {
        if (ULLONG_MAX - (din % 5) * temp < *pin) return 1;
        *pin += (din % 5) * temp;
        temp *= 10;
        din /= 5;
    }
    return 0;
}

int main(void) {
    ull pin, din;
    scanf("%llu%llu", &pin, &din);
    printf("%llu\n", ftod(pin));
    int result = dtof(din, &pin);
    if (result == 0)
        printf("%llu", pin);
    else
        printf("!");

}