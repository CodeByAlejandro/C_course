#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * promptString(void);

int main(int argc, char **argv) {

	char * const pString = promptString();

	printf("The string entered is:\n");
	printf("\"%s\"\n", pString);
	printf("It takes up %zd bytes in memory.\n", strlen(pString) + 1);

	free(pString);
	
	printf("\n");
	return 0;
}

char * promptString(void) {
	printf("Enter a string of random lenght: ");

	char * pString = (char *) malloc(sizeof(char));
	
	if (!pString) {
		fprintf(stderr, "Could not allocate string memory!");
	}

	int count = 0;
	while ((pString[count] = (char) getchar()) != '\n' && pString[count] != EOF) {
		pString = realloc(pString, (count + 2) * sizeof(char));
		if(!pString) {
			fprintf(stderr, "Could not reallocate string memory!");
		};
		count++;
	}
	if (pString[count] == EOF) {
		printf("\n");
	}
	pString[count] = '\0';
	
	return pString;
}