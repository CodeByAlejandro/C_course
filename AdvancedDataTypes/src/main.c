#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

void VLAs(void);
void flexibleArrayMembers(void);
void complexNumbers(void);

int main(int argc, char **argv) {
	VLAs();
	flexibleArrayMembers();
	complexNumbers();

	return 0;
}

void VLAs(void) {
	int count = 0;
	int sum = 0;
	
	printf("Enter amount of numbers to add: ");
	scanf("%d", &count);
	
	int numbers[count];
	
	for(int i = 0; i < count; i++) {
		printf("Enter number %d > ", i + 1);
		scanf("%d", &numbers[i]);
	}
	
	for(int i = 0; i < count; i++) {
		sum += numbers[i];
	}
	
	printf("The sum of the numers is %d\n", sum);
}

void flexibleArrayMembers(void) {
	struct myArray {
		int length; // we need one fixed struct member anyway
		int array[]; // this must be the last member
	} * pMyArray = NULL;
	
	int count = 0;

	printf("Enter amount of numbers to add: ");
	scanf("%d", &count);
	
	pMyArray = (struct myArray *) malloc(sizeof(struct myArray) + (count * sizeof(int)));
	
	pMyArray->length = count;
	
	for(int i = 0; i < count; i++) {
		printf("Enter number %d > ", i + 1);
		scanf("%d", &(pMyArray->array[i]));
	}
	
	printf("\nElements in the flexible array member in the struct:\n");
	
	for(int i = 0; i < pMyArray->length; i++) {
		printf("%d ", pMyArray->array[i]);
	}
	
	printf("\n");
	free(pMyArray);
}

void complexNumbers(void) {
	double complex z1 = I * I;
	printf("I * I: %.2f%+.2fi\n", creal(z1), cimag(z1));
	
	double complex z2 = pow(I, 2);
	printf("I ^ 2: %.2f%+.2fi\n", creal(z2), cimag(z2));
	
	const double PI = acos(-1);
	double complex z3 = I * PI;
	printf("I * PI: %.2f%+.2fi\n", creal(z3), cimag(z3));

	double complex z4 = 1+2*I;
	double complex z5 = 1-2*I;

	double complex z6 = conj(z4);
	double complex z7 = conj(z5);
	printf("conj(1+2I): %.2f%+.2fi\n", creal(z6), cimag(z6));
	printf("conj(1-2I): %.2f%+.2fi\n", creal(z7), cimag(z7));

	printf("\n");
}