#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <setjmp.h>

jmp_buf buf;

// For timing call the program as ./DynamicMemory2 <<< 'Some string goes here'
// Otherwise the user input time will be counted as well
long timeFunction(char * (*readString)(const char *, unsigned int), const char * promptString, unsigned int blockSize, char ** pStringRetVal);
char * readString(const char * readString, unsigned int blockSize);

int main(int argc, char **argv) {
	if(setjmp(buf))
		return 1;

	char * stringRetVal = NULL;
	long elapsed_ns = timeFunction(readString, "Enter a string of random lenght: ", 1, &stringRetVal);

	printf("\nThe string entered is:\n");
	printf("\"%s\"\n", stringRetVal);
	printf("It takes up %zd bytes in memory.\n", strlen(stringRetVal) + 1);
	
	free(stringRetVal);
	stringRetVal = NULL;

	printf("\nThe promptString() function took %ldns.\n", elapsed_ns);
	
	printf("\n");
	return 0;
}

long timeFunction(char * (*readString)(const char *, unsigned int), const char * promptString, unsigned int blockSize, char ** pStringRetVal) {
	struct timespec start, end;
	
	// Get start time
	clock_gettime(CLOCK_MONOTONIC, &start);

	// run function via func pointer
	char * pString = readString(promptString, blockSize);

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

char * readString(const char * promptString, unsigned int blockSize) {
	printf("%s", promptString);

	char * pString = (char *) malloc(blockSize * sizeof(char));
	if (!pString) {
		fprintf(stderr, "Could not allocate memory for iten name string!\n");
		longjmp(buf, 1);
	}

	int idx = 0;
	int blocks = 1;
	while((pString[idx] = getchar()) != '\n' && pString[idx] != EOF) {
		if (idx == (blocks * blockSize) - 1) {
			char * const pNewString = realloc(pString, (++blocks * blockSize) * sizeof(char));
			if (!pNewString) {
				fprintf(stderr, "Could not reallocate memory for iten name string!\n");
				free(pString);
				longjmp(buf, 1);
			} else {
				pString = pNewString;
			}
		}
		idx++;
	}
	pString[idx] = '\0';
	
	return pString;
}