#include<stdio.h>
#include<stdlib.h>
#include "math_header.h" 

double math_square(double num) {
    return num * num;
}
/** This function is not 100% accurate, but conceptually a valid solution.
 * Lack of Precision: The method of iterating and squaring numbers is approximate. It won't give you an exact square root, which can be problematic for applications where precision matters.
 * Inefficient: This approach requires a loop that iterates through numbers, squaring each one until it meets the criteria. For large numbers, this can be very slow.
 */
double math_sqrt(double find) {
    double result = 0.0;
    double squareNumber = 1.0;
    while(1) {
        result = math_square(squareNumber); //Square the number
        if(result >= find) { //Check if its equal or larger than what we need to find.
            break;
        }
        squareNumber+= 0.1;
    }
    return squareNumber;
}

int main (int c, char** args) {
    //TODO: use the sqrt function.
     if (c < 1) {
        printf("Usage: %s <number>\n", args[0]);
        return 1;
    }
    printf("Result: %8.3lf\n", (double) math_sqrt(atoi(args[1])));
    return 0;
}
