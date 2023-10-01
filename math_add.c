#include<stdio.h>
#include <stdlib.h>
#include "math_header.h"

double add (int c, char *a[]) {
    double sum = atof(a[1]);
    for (int i = 2; i < c; i++) {
        printf("Add %8.3lf + %8.3lf\n", sum, atof(a[i]));
        sum += atof(a[i]);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <number> <number> ...\n", argv[0]);
        return 1;
    }
    printf("Result: %8.3lf\n", (double) add(argc,argv));
    return 0;
}