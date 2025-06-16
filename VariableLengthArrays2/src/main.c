#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	int arraySize = 2;
	if (argc > 1) {
		arraySize = (int) strtod(argv[1], NULL);
	}
	
	int myArray[arraySize];
	
	myArray[0] = 2;
	myArray[1] = 3;

	for (int i = 0; i < arraySize; i++) {
		printf("%d ", myArray[i]);
	}
	printf("\n\n");

	return 0;
}