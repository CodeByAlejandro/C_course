#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *reverseString(char *string, char *reversed);
// returns a pointer (first pointer) to an array of 100 chars (only the first dimension decays into a pointer)
char (*sortStrings(char strings[][100], int nbrOfStrings))[100];

int main(void) {
    /****************************************
    * Part 1: reverse a string              *
    ****************************************/
    char string[100];
    char reverse[100];
    
    printf("Give me a string to reverse: ");
    gets(string);
    reverseString(string, reverse);
    printf("Reverse string is: '%s'\n", reverse);
    
    
    /****************************************
    * Part 2: bubble sort array of strings  *
    ****************************************/
    char strings[100][100];
    
    // Retrieve number of strings
    int nbrOfStrings = 0;
    printf("Input number of strings: ");
    bool validInput = false;
    while (!validInput) {
        scanf("%d", &nbrOfStrings);
        for (char c; (c = getchar()) != '\n' && c != EOF;);
        if (nbrOfStrings >= 1 && nbrOfStrings <= 100) {
            validInput = true;
        } else {
            printf("Please provide a valid integer between 1 and 100 (inclusive)!\n");
        }
    }
    
    // Retrieve number of strings into 2D char array
    for (int i = 0; i < nbrOfStrings; i++) {
        printf("String %d: ", i + 1);
        gets(strings[i]);
    }
    
    // Sort 2D char array with strings
    char (*sortedStrings)[100] = sortStrings(strings, nbrOfStrings);
    
    // Display sorted 2D char array with strings
    printf("Sorted strings:\n");
    for (int i = 0; i < nbrOfStrings; i++) {
        printf("%s\n", strings[i]);
    }
    
        // Display sorted 2D char array with strings
    printf("Sorted strings:\n");
    for (int i = 0; i < nbrOfStrings; i++) {
        printf("%s\n", sortedStrings[i]);
    }
}

char *reverseString(char *string, char *reversed) {
    int maxIdx = strlen(string) - 1;
    for (int i = maxIdx; i != -1; i--) {
        reversed[maxIdx - i] = string[i];
    }
    reversed[maxIdx + 1] = '\0';
    return reversed;
}

char (*sortStrings(char strings[][100], int nbrOfStrings))[100] {
    char temp[100];
    for (int i = nbrOfStrings - 2; i != -1; i--) {
        for (int j = 0; j <= i; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                strncpy(temp, strings[j + 1], 100);
                strncpy(strings[j + 1], strings[j], 100);
                strncpy(strings[j], temp, 100);
            }
        }
    }
    return strings;
}