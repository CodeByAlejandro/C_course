#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INPUT "numbers.txt"

bool isPrime(int num);

int main(int argc, char **argv) {
	FILE * fp = fopen(INPUT, "r");
	if(!fp) {
		fprintf(stderr, "Could not open %s!\n", INPUT);
		exit(EXIT_FAILURE);
	}
	
	printf("File opened successfully, Reading integers from file.\n\n");
	
	for(char line[255]; fgets(line, 255, fp) != NULL;) {
		int num = 0, nread = 0;
		char * next = line;
		while(sscanf(next, "%d%n", &num, &nread) == 1) {
			bool odd = num % 2 == 1;			
			if(odd) {
				if(isPrime(num)) {
					printf("Prime number found: %d\n", num);
				} else {
					printf("Odd number found: %d\n", num);
				}
			} else {
				printf("Even number found: %d\n", num);
			}
			next += nread;
		}
	}

	if(ferror(fp)) {
		fprintf(stderr, "Error reading %s!\n", INPUT);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	
	fclose(fp);
	printf("\n");
	return 0;
}

bool isPrime(int num) {
	if(num < 2 || num % 2 == 0)
		return false;
	for(int i = 3; num / i >= i; i+=2) {
		if (num % i == 0)
			return false;
	}
	return true;
}