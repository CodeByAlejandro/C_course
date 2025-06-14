#include <stdio.h>

#define PAYRATE 12.00f
#define TAX_LEVEL_1 .15
#define TAX_LEVEL_2 .20
#define TAX_LEVEL_3 .25

int main(int argc, char **argv) {
	float hoursWorked = 0;
	float grossPay = 0;
	float netPay = 0;
	float taxes = 0;

	printf("Enter weekly hours worked: ");
	scanf("%f", &hoursWorked);
	

	if (hoursWorked > 0 && hoursWorked <= 40) {
		grossPay = hoursWorked * PAYRATE;
	} else if (hoursWorked > 40) {
		grossPay = 40 * PAYRATE + (hoursWorked - 40) * PAYRATE * 1.5;
	}
	
	taxes += (grossPay > 300 ? 300 : grossPay) * TAX_LEVEL_1;

	if (grossPay > 300) {
		double grossPayAbove300 = grossPay - 300;
		taxes += (grossPayAbove300 > 150 ? 150 : grossPayAbove300) * TAX_LEVEL_2;
	}

	if (grossPay > 450) {
		taxes += (grossPay - 450) * TAX_LEVEL_3;
	}
	
	netPay = grossPay - taxes;
	
	printf("Your weekly payment:\n");
	printf("\tGross pay: \t%.3f\n", grossPay);
	printf("\tTaxes: \t\t%.3f\n", taxes);
	printf("\tNet pay: \t%.3f\n", netPay);
	printf("\n");

	return 0;
}