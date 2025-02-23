#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int strLength = 0;
    printf("Enter the max length of a string to enter: ");
    scanf("%d", &strLength);
    for(char c; ((c = getchar()) != '\n'););
    
    char *string = (char *) malloc(++strLength * sizeof(char));
    if (!string) {
        printf("Could not allocate memory!\n");
        return 1;
    }
    printf("Enter your string: ");
    fgets(string, strLength, stdin);
    
    // Remove the included newline in string array itself
    char *pString = string;
    while (*pString)
        pString++;
    pString--;
    if (*pString == '\n')
        *pString = '\0';
    
    printf("\nString entered: '%s'\n", string);
    
    /* realloc(string, 0) is same as:
     *     free(string);
     *     string = NULL;
     */
    if(!realloc(string, 0))
        return 1;
    
    return 0;
}