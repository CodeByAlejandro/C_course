#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double sumNDoubles(unsigned char n, ...);

int main(int argc, char **argv) {
	printf("Sum: %.2f\n", sumNDoubles(0));
	printf("Sum: %.2f\n", sumNDoubles(1, 2.0));                // 2.0
	printf("Sum: %.2f\n", sumNDoubles(2, 2.0, 3.5));           // 5.5
	printf("Sum: %.2f\n", sumNDoubles(4, 1.5, 2.7, 3.3, 5.9)); // 13.4

	printf("\n");
	return 0;
}

double sumNDoubles(unsigned char n, ...) {
	va_list ap;
	double sum = 0;

	va_start(ap, n);
	for(unsigned char i = 0; i < n; i++) {
		sum += va_arg(ap, double);
	}
	va_end(ap);

	return sum;
}