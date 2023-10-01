#include<stdio.h>
#include <stdlib.h>
#include "math_header.h"


double sub (int numArgs, char *args[]) {
    double sum = atof(args[1]);
    for (int i = 2; i < numArgs; i++) {
        sum -= atof(args[i]);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <number> <number> ...\n", argv[0]);
        return 1;
    }
    printf("Result: %8.3lf\n", (double) sub(argc,argv));
    return 0;
}