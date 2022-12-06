#include "stdio.h"
#include "math.h"

#define M_2PI (2.*M_PI)

int process(double a, double b, double c, double *p, double *s) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a + b == c || a + c == b || b + c == a) {
        *s = 0;
        *p = a + b + c;
        return 2;
    }
    if (a + b < c || a + c < b || b + c < a) return 3;
    double P = (a + b + c) / 2.0;
    *s = sqrt(P * (P - a) * (P - b) * (P - c));
    *p = a + b + c;
    return 0;
}

int solve(double *x, double a, double c) {
    double q, r, r2, q3;
    q = (a * a) / 9.;
    r = (a * (2. * a * a) + 27. * c) / 54.;
    r2 = r * r;
    q3 = q * q * q;
    if (r2 < q3) {
        double t = acos(r / sqrt(q3));
        a /= 3.;
        q = -2. * sqrt(q);
        x[0] = q * cos(t / 3.) - a;
        x[1] = q * cos((t + M_2PI) / 3.) - a;
        x[2] = q * cos((t - M_2PI) / 3.) - a;
        return (3);
    } else {
        double aa, bb;
        if (r <= 0.) r = -r;
        aa = -pow(r + sqrt(r2 - q3), 1. / 3.);
        if (aa != 0.) bb = q / aa;
        else bb = 0.;
        a /= 3.;
        q = aa + bb;
        r = aa - bb;
        x[0] = q - a;
        x[1] = (-0.5) * q - a;
        x[2] = (sqrt(3.) * 0.5) * fabs(r);
        if (x[2] == 0.) return (2);
        return (1);
    }
}

int reverse_process(double p, double s, double *a, double *c, int* ans_counter) {
    if (p <= 0 || s < 0) return 1;
    if (s == 0) {
        a[0] = p / 2;
        c[0] = p;
        *ans_counter = 1;
        return 2;
    }
    double temp[3];
    *ans_counter = 0;
    int r = solve(temp, (-p / 2), (8 * s * s / p));
    for (int i = 0; i < r; ++i) {
        if (temp[i] > 0 && (p - temp[i]) / 2 > 0) {
            a[*ans_counter] = (p - temp[i]) / 2;
            c[*ans_counter] = temp[i];
            (*ans_counter)++;
        }
    }
    if (*ans_counter == 0) return 3;

    return 0;
}

int main(void) {
    double a, b, c, s, p;
    scanf("%lf%lf%lf", &a, &b, &c);
    int result = process(a, b, c, &s, &p);
    printf("%d\n", result);
    if (result == 0 || result == 2) {
        printf("%.6lf\n%.6lf", p, s);
    }

//     2 task
//    int counter = 0;
//    double s, p;
//    double a[3], c[3];
//    scanf("%lf%lf", &s, &p);
//    int result = reverse_process(p, s, a, c, &counter);
//    printf("%d %d\n", result, counter);
//    for (int i = 0; i < counter; ++i) {
//        printf("%lf %lf %lf\n", a[i], a[i], c[i]);
//    }
}