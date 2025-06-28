#include <stdio.h>

int main(int argc, char **argv) {
	int base = 0;
	int middle = 0;
	int line = 0;
	int column = 0;

	input:
	printf("Enter an uneven number as the base for the tree: ");
	scanf("%d", &base);

	if(base % 2 == 0) {
		fprintf(stderr, "The number is not uneven!\n");
		goto input;
	}

	printf("\n");	
	middle = base / 2;

	printLine:
	column = 0;
	printChar:
	if(column == middle - line || column == middle + line || middle - line == 0) {
		printf("*");
		column++;
	} else {
		printf(" ");
		column++;
	}
	if(column != base) {
		goto printChar;
	}
	else {
		printf("\n");
		if(middle - line != 0) {
			line++;
			goto printLine;
		} else {
			goto end;
		}
	}
	
	end:
	printf("\n");
	return 0;
}