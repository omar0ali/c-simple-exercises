/**
 * @file input_function.h
 * @brief A simple input function for user interaction.
 */

#ifndef INPUT_LIB_H
#define INPUT_LIB_H


#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Read a line of text from the user and return it as a dynamically allocated string.
 *
 * This function reads a line of text from the user, allocates memory for the string, and
 * returns the user input as a dynamically allocated string. The caller is responsible for
 * freeing the memory allocated by this function when it's no longer needed to prevent memory
 * leaks.
 *
 * @return A dynamically allocated string containing the user's input. NULL on error.
 */
char * input(char *strs){
    printf("%s", strs);
    char c;
    char * output = (char *)malloc(100 * sizeof(char));
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    int index = 0;
    while((c= getchar()) != '\n') {
        output[index] = c;
        index++;
    }
    output[index] = '\0';
    return output;
}

#endif // INPUT_LIB_H