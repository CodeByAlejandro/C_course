#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define SUM(a, b) ((a) + (b))
#define SQUARE(x) ((x) * (x))
#define CUBE(x) (SQUARE(x) * (x))
#define IS_UPPER(c) isupper(c)
#define IS_LOWER(c) (c >= 97)

#define PRINT_ERR(...) fprintf(stderr, __VA_ARGS__)

static inline double square(double x);

int main(int argc, char **argv) {

	printf("The current function is %s\n", __func__);
	printf("This is line %d in file %s\n", __LINE__, __FILE__);
	printf("This program was compiled on %s at %s\n", __DATE__, __TIME__);
	#if __STDC__ == 1
		puts("This compiler supports the ISO C standard.");
	#else
		puts("This compiler does not support the ISO C standard.");
	#endif
	printf("\n");
	
	printf("The sum of 3 and (4 * 2) is: %d\n", SUM(3, 4 * 2));
	printf("The square and cube of 4 are respectively %d and %d\n", SQUARE(4), CUBE(4));
	printf("The square of 4 using inline func is %.2f\n", square(4));
	printf("The character A is %s\n", IS_UPPER('A') ? "upper case" : "lower case");
	printf("The character a is %s\n", IS_LOWER('a') ? "lower case" : "upper case");
	
	char c = 0;
	bool validCharEntered = false;
	do {
		printf("Enter a alfanumeric character: ");
		scanf("%c", &c);
		if(!isalpha(c)) {
			PRINT_ERR("Value entered '%c' is not an alfanumeric character!\n", c);
			if(c != '\n') {
				while((c = getchar()) != '\n' && c != EOF);
			}
			if(feof(stdin))
				clearerr(stdin);
			continue;
		}
		validCharEntered = true;
	} while(!validCharEntered);
	printf("The entered character is %s\n", IS_UPPER(c) ? "upper case" : "lower case");

	printf("\n");
	return 0;
}

static inline double square(double x) {
	return x * x;
}