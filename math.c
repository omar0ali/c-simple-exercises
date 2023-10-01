#include <stdio.h>
#include <stdlib.h>

void math(char **operation) {
    double result = 0;
    double fnum = atof(operation[1]);
    char op = *operation[2];
    double snum = atof(operation[3]);

    switch (op)
    {
    case '+':   
        result = fnum + snum;
        break;
    case '-':
        result = fnum - snum;
        break;
    case '*':
        result = fnum * snum;
        break;
    case '/': 
        result = fnum / snum;
        break;
    default:
        printf("Wrong opeartion was provided! \n");
        return;
        break;
    }
    printf("%.2lf %c %.2lf = %.2lf\n", fnum, op, snum, result);
}

int main (int c, char **args) { 
    if(c != 4) {
        printf("Usage: %s <first number> <operation> <second number>\nOP: + - * /\n", args[0]);
        return 1;
    }
    math(args);
    return 0;
}