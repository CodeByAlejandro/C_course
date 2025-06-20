#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// For timing call the program as ./DynamicMemory2 <<< 'Some string goes here'
// Otherwise the user input time will be counted as well
long timeFunction(char * (*promptString)(unsigned int), unsigned int blockSize, char ** pStringRetVal);
char * promptString(unsigned int blockSize);

int main(int argc, char **argv) {
	char * stringRetVal = NULL;
	long elapsed_ns = timeFunction(promptString, 1, &stringRetVal);

	printf("\nThe string entered is:\n");
	printf("\"%s\"\n", stringRetVal);
	printf("It takes up %zd bytes in memory.\n", strlen(stringRetVal) + 1);
	
	free(stringRetVal);
	stringRetVal = NULL;

	printf("\nThe promptString() function took %ldns.\n", elapsed_ns);
	
	printf("\n");
	return 0;
}

long timeFunction(char * (*promptString)(unsigned int), unsigned int blockSize, char ** pStringRetVal) {
	struct timespec start, end;
	
	// Get start time
	clock_gettime(CLOCK_MONOTONIC, &start);

	// run function via func pointer
	char * pString = promptString(blockSize);

	// Get end time
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	// Return string return value from function via pointer
	*pStringRetVal = pString;
	
	// Calculate elapsed time in nanoseconds
    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    long elapsed_ns = seconds * 1000000000L + nanoseconds;
	
	return elapsed_ns;
}

char * promptString(unsigned int blockSize) {
	printf("Enter a string of random lenght: ");

	char * pString = (char *) malloc(blockSize * sizeof(char));
	
	if (!pString) {
		fprintf(stderr, "Could not allocate string memory!");
	}

	int count = 0;
	int blocks = 1;
	while ((pString[count] = (char) getchar()) != '\n' && pString[count] != EOF) {
		if (count == (blocks * blockSize) - 1) {
			pString = realloc(pString, (++blocks * blockSize) * sizeof(char));
			if(!pString) {
				fprintf(stderr, "Could not reallocate string memory!");
			};
		}
		count++;
	}
	pString[count] = '\0';
	
	return pString;
}