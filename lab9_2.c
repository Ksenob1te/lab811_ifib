#include "stdio.h"
#include "stdlib.h"
#define ul unsigned long

ul ftod(ul pin) {
    ul din = 0;
    ul temp = 1;
    while (pin) {
        din += temp * (pin % 10);
        temp *= 5;
        pin /= 10;
    }
    return din;
}

int dtof(ul din, ul *pin) {
    *pin = 0;
    ul temp = 1;
    while (din) {
        if (ULONG_MAX - (din % 5) * temp < *pin) return 1;
        *pin += (din % 5) * temp;
        temp *= 10;
        din /= 5;
    }
    return 0;
}

int sum(ul a, ul b, ul *sum) {
    ul ad = ftod(a);
    ul bd = ftod(b);
    if (ULONG_MAX - ad < bd) return 1;
    ul sd = ad + bd;
    ul s;
    int result = dtof(sd, &s);
    if (result == 0) {*sum = s; return 0;}
    else return 1;
}

int mult(ul a, ul b, ul *sum) {
    ul ad = ftod(a);
    ul bd = ftod(b);
    if (ULONG_MAX / ad < bd) return 1;
    ul sd = ad * bd;
    ul s;
    int result = dtof(sd, &s);
    if (result == 0) {*sum = s; return 0;}
    else return 1;
}

int subs(ul a, ul b, ul *sum) {
    ul ad = ftod(a);
    ul bd = ftod(b);
    if (bd > ad) return 1;
    ul sd = ad - bd;
    ul s;
    int result = dtof(sd, &s);
    if (result == 0) {*sum = s; return 0;}
    else return 1;
}

int process(ul a, ul b, ul *ans) {
    ul p;
    int result = subs(b, a, &p);
    if (result) return 2;
    result = mult(b, p, &p);
    if (result) return 3;
    result = sum(b, p, &p);
    if (result) return 1;
    *ans = p;
    return 0;
}

int main(void) {
    ul a, b, p;
    scanf("%lu%lu", &a, &b);
    int result = process(a, b, &p);
    if (result == 0)
        printf("%lu\n", p);
    else
        printf("!%d\n", result);

}
