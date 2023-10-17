#include<stdio.h>
#include<stdlib.h>
#include "math_header.h" 

int math_square(int num) {
    return num * num;
}
/** This function is not 100% accurate, but conceptually a valid solution.
 * Lack of Precision: The method of iterating and squaring numbers is approximate. It won't give you an exact square root, which can be problematic for applications where precision matters.
 * Inefficient: This approach requires a loop that iterates through numbers, squaring each one until it meets the criteria. For large numbers, this can be very slow.
 * Limited to Integers: This method only works for integer square roots.
*/
int math_sqrt(int find) {
    int result = 0;
    int squareNumber = 1;
    while(1) {
        result = math_square(squareNumber); //Square the number
        if(result >= find) { //Check if its equal or larger than what we need to find.
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
