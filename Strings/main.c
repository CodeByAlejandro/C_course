#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getStrLength(const char string[]);
int getStrLength2(const char *string);
char *concatStrings(const char string1[], const char string2[]);
void concatStrings2(char result[], const char string1[], const char string2[]);
bool compareStrings(const char *string1, const char *string2);

int main(int argc, char **argv)
{
	char someString[] = "This is my string.";
    
    int strLength = getStrLength(someString);
    printf("String length is %d\n", strLength);
    int strLength2 = getStrLength2(someString);
    printf("String length2 is %d\n", strLength2);
    
    char someOtherString[] = " This is my other string.";
    char *result = concatStrings(someString, someOtherString);
    printf("Concatenated string: \"%s\"\n", result);
    free(result);
    
    char result2[50];
    concatStrings2(result2, someString, someOtherString);
    printf("Concatenated string: \"%s\"\n", result2);
    
    bool equal;
    equal = compareStrings(someString, someOtherString);
    printf("'%s' and '%s' are %s\n", someString, someOtherString, equal ? "equal" : "not equal");
    
    char equalStartString[] = "This is my string. ";
    equal = compareStrings(someString, equalStartString);
    printf("'%s' and '%s' are %s\n", someString, equalStartString, equal ? "equal" : "not equal");
    
    char equalString[] = "This is my string.";
    equal = compareStrings(someString, equalString);
    printf("'%s' and '%s' are %s\n", someString, equalString, equal ? "equal" : "not equal");
    
	return 0;
}

int getStrLength(const char string[]) {
    int count = 0;
    for (; string[count] != '\0'; count++);
    return count;
}

int getStrLength2(const char *string) {
    int count = 0;
    for (; string[count] != '\0'; count++);
    return count;
}

char *concatStrings(const char string1[], const char string2[]) {
    int concatLength = getStrLength(string1) + getStrLength(string2);
    char *result = (char *) malloc((concatLength + 1) * sizeof(char));
    
    int resultIdx = 0;
    for (; string1[resultIdx] != '\0'; resultIdx++) {
        result[resultIdx] = string1[resultIdx];
    }
    for (int i = 0; string2[i] != '\0'; i++, resultIdx++) {
        result[resultIdx] = string2[i];
    }
    result[resultIdx] = '\0';
    
    return result;
}

void concatStrings2(char result[], const char string1[], const char string2[]) {
    int resultIdx = 0;
    for (; string1[resultIdx] != '\0'; resultIdx++) {
        result[resultIdx] = string1[resultIdx];
    }
    for (int i = 0; string2[i] != '\0'; i++, resultIdx++) {
        result[resultIdx] = string2[i];
    }
    result[resultIdx] = '\0';
}

bool compareStrings(const char *string1, const char *string2) {
    bool equal = true;
    int i = 0;
    for (; string1[i] != '\0' && string2[i] != '\0'; i++) {
        if (string1[i] != string2[i]) {
            equal = false;
            break;
        }
    }
    if ((string1[i] == '\0' && string2[i] != '\0') || (string2[i] == '\0' && string1[i] != '\0')) {
        equal = false;
    }
    return equal;
}