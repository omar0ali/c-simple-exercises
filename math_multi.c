#include <stdio.h>
#include <stdlib.h>
#include "math_header.h"

double multiply(int c, char *a[])
{
    double product = 1.0;
    for (int i = 1; i < c; i++)
    {
        if (atof(a[i]) == 0.0)
        {
            fprintf(stderr, "E: Multiplying by zero encountered.\n");
            return 1;
        }
        if (i > 1) {
            printf("Multiply %8.3lf * %8.3lf\n", product, atof(a[i]));
        }
        product *= atof(a[i]);
    }
    return product;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <number> <number> ...\n", argv[0]);
        return 1;
    }
    printf("Result: %8.3lf\n", (double)multiply(argc, argv));
    return 0;
}