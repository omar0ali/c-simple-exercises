/**
 * @file input_lib.h
 * @brief A simple input function for user interaction.
 */

#ifndef INPUT_LIB_H
#define INPUT_LIB_H


#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Count the characters from a string.
 * @return Number of characters in the string.
 */

int len(char * strs) {
    int counter = 0;
    while(strs[counter]!='\0') {
        counter ++;
    }
    return counter;
}

/**
 * @brief Read a line of text from the user and return it as a dynamically allocated string.
 *
 * This function reads a line of text from the user, allocates memory for the string, and
 * returns the user input as a dynamically allocated string. 
 * 
 * NOTE: The caller is responsible for freeing the memory allocated by this function when it's no longer needed to prevent memory leaks.
 *
 * @return A dynamically allocated string containing the user's input. NULL on error.
 */
char * input(char *strs){
    printf("%s", strs);
    char c;
    char * output = (char *)malloc(len(strs) * sizeof(char));
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


/*  
    USING TRIM()
    char* output = trimLeading("         Hello World ann how are you.    ");
    printf("Leading:->%sEND\nSize: %d\n", output, len(output));
    output = trimTrailing("         Hello World ann how are you.    ");
    printf("Trailing:->%sEND\nSize: %d\n", output, len(output));
    output = trim("         Hello World ann how are you.    ");
    printf("Trim:->%sEND\nSize: %d\n", output, len(output));
    free(output);
*/

char * trimTrailing(char * strs) {
    int lengthOfString = len(strs);
    int inputIndex = lengthOfString - 1;
    while (inputIndex >= 0 && strs[inputIndex] == ' ') {
        inputIndex--;
    }
    char *output = (char *)calloc(inputIndex + 2, sizeof(char)); //Note: used '+2' because we will need additional character to store the null-terminator ('\0')
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    int outputIndex = 0;
    while (outputIndex <= inputIndex) {
        output[outputIndex] = strs[outputIndex];
        outputIndex++;
    }
    output[outputIndex] = '\0';
    return output;
}

char * trimLeading(char *strs) {
    char * output = (char *) calloc(len(strs), sizeof(char));
    if(output == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    int startReadingFlag = 0;
    int inputIndex = 0;
    int outputIndex = 0;
    while(strs[inputIndex]!='\0') {
        if(strs[inputIndex] == ' ' && startReadingFlag == 0) {
            inputIndex++;
            continue;
        }else {startReadingFlag = 1;}
        output[outputIndex] = strs[inputIndex];
        inputIndex++;
        outputIndex++;
    }
    output[outputIndex] = '\0';
    return output;
}

char * trim(char*strs) {
    char * val = trimLeading(strs);
    val = trimTrailing(val);
    return val;
}


void copyTo(char *copied, char *to) {
    int i = 0;
    for (; i < len(copied); i++) {
        to[i] = copied[i];
    }
    to[i] = '\0';
}


#endif // INPUT_LIB_H