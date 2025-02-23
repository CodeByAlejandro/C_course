#include <stdio.h>

long getStrLen(const char *str);

int main(int argc, char **argv)
{
	char *string = "My string";
    long strLen = getStrLen(string);
    printf("The string is %ld characters long\n", strLen);
    printf("The string is %ld characters long\n", getStrLen(""));
    
	return 0;
}

long getStrLen(const char *str) {
    const char *const strStart = str;
    while (*str) {
        str++;
    }
    return str - strStart;
}