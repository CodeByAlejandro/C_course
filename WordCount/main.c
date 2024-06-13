#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Press CTRL + D (unix) twice to input a EOF if there is already text in the input buffer that still needs to be send

int main(int argc, char **argv)
{
    // Get the file pointer
    FILE *fp = NULL;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            fprintf(stderr, "Couldn't open file '%s'!\n", argv[1]);
            exit(1);
        }
    } else {
        fp = stdin;
    }
    
    // Read the file to count characters and words
    long long charCnt = 0;
    long long wordCnt = 0;
    bool nonWhspCharFound = false;
    for (int c; (c = getc(fp)) != EOF; charCnt++) {
        if (isspace(c)) {
            // if this is the first whitespace character after non-whitespace
            if (nonWhspCharFound) {
                wordCnt++;
                nonWhspCharFound = false;
            }
        } else {
            nonWhspCharFound = true;
        }
    }
    // Add last word in case there is no trailing whitespace
    if (nonWhspCharFound) {
        wordCnt++;
    }
    
    // Close the file
    fclose(fp);
    
    // Print out the results
    printf("The input contains %lld characters\n", charCnt);
    printf("The input contains %lld words\n", wordCnt);
   
	return 0;
}
