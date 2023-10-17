#include<stdio.h>
#include<stdlib.h>
#include "math_header.h" 

int math_square(int num) {
    return num * num;
}

int math_sqrt(int find) {
    int result = 0;
    int squareNumber = 1;
    while(1) {
        result = math_square(squareNumber);
        if(result >= find) {
            break;
        }
        squareNumber++;
    }
    return squareNumber;
}

int main (int c, char** args) {
    //TODO: use the sqrt function.
     if (c < 1) {
        printf("Usage: %s <number>\n", args[0]);
        return 1;
    }
    printf("Result: %d\n", (int) math_sqrt(atoi(args[1])));
    return 0;
}
