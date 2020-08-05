#include <stdio.h>

// 반복적 구현
double slow_power_iter(double x, int n) {
    int i;
    double r = 1.0;
    for (i = 0; i < n; i++) {
        r = r * x;
    }
    return r;
}

// 순환적 구현
double slow_power(double x, int n) {
    if (n == 0) return 1;
    else if ((n % 2) == 0) {
        return slow_power(x * x, n / 2);
    }
    else {
        return x * slow_power(x * x, (n - 1) / 2);
    }
}

void main() {
    double X, N;
    printf("X_N Program\n");
    printf("Input X : ");
    scanf("%lf", &X);
    printf("Input N : ");
    scanf("%lf", &N);

    printf("%.lf^%.lf is %.lf. (Iteration)\n", X, N, slow_power_iter(X, N));
    printf("%.lf^%.lf is %.lf. (Recursion)\n", X, N, slow_power(X, N));
}