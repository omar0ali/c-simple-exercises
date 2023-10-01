#include <string.h>
#include <stdio.h>
#include <stdbool.h>


bool palindrome(char word[]) {
    int len = strlen(word)-1;
    int middle = len /2;
    for (int i = 0;i<middle;i++){
        if(word[i] != word[len - i]) {
            return false;
        }
    }
    return true;
}


// Usage: palindrome <input_text>
int main(int argc, char **word) {
    bool result = palindrome(word[1]);
    if(result) {
        printf("It is a plindrome.\n");
    }else {
        printf("It is not a plindrome.\n");
    }
    return 0;
}