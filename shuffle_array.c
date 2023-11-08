#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is a function to check if a number exist in an array
int isIntegerInArray(int target, int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return 1; // The integer is in the array
        }
    }
    return 0; // The integer is not in the array
}
void shuffle(int n, char *array[])
{
    srand(time(NULL)); // Seed the random number generator
    int size = n-1;
    int result[size];
    int usedNumbers[size];
    int i = 0;
    while (i < size)
    {
        int randomIndex = rand() % size;
        if (isIntegerInArray(randomIndex, usedNumbers, size) == 0)
        {
            usedNumbers[i] = randomIndex;
            result[i] = atoi(array[randomIndex]);
            i++;
        }
    }
    for (int i = 0; i < size; i++) {
        printf(" %d ", usedNumbers[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf(" %d ", result[i]);
    }
}

int main(int c, char *args[])
{
    shuffle(c, args);
    return 0;
}