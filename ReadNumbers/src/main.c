#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char **argv) {
	
	long sum = 0;
	int count = 0;

	printf("Enter 'quit' to stop entering numbers...\n");

	for(char inputStr[20]; !feof(stdin);) {
		// Read string number from stdin
		printf("Enter integral number %d > ", count + 1);
		if(!fgets(inputStr, sizeof(inputStr), stdin)) {
			if(ferror(stdin)) {
				fprintf(stderr, "Error reading input!\n");
				exit(EXIT_FAILURE);
			}
		}
		
		/* Case insensitive compare to "quit" */
		char * pInputChar;
		for(pInputChar = inputStr; (*pInputChar = (char) tolower(*pInputChar)); pInputChar++);
		// Remove ending newline from input string
		if(*--pInputChar == '\n') {
			*pInputChar = '\0';
		}
		if(strcmp(inputStr, "quit") == 0) {
			break;			
		}

		// Convert string to long number
		char * pEnd;
		long num = strtol(inputStr, &pEnd, 10);
		if(*pEnd != '\0') {
			fprintf(stderr, "The text entered is not a valid integral number!\n");			
			continue;
		}
		
		// Calculate sum
		sum += num;
		
		// Update counter
		count++;
	}
	
	if(feof(stdin))
		printf("\n");

	printf("The sum is %ld\n", sum);

	return 0;
}