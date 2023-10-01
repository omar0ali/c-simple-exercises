#include<stdio.h>
#include <stdlib.h>
#include "math_header.h"

double division(int c, char *a[]) {
    double quotient = atof(a[1]); 
    for (int i = 2; i < c; i++) {
        double divisor = atof(a[i]);
        if (divisor == 0.0) {
            fprintf(stderr, "E: Division by zero encountered.\n");
            return 1.0;
        }
        printf("Divide %8.3lf / %8.3lf\n", quotient, divisor);
        quotient /= divisor;
    }
    return quotient;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <number> <number> ...\n", argv[0]);
        return 1;
    }
    printf("Result: %8.3lf\n", (double) division(argc,argv));
    return 0;
}