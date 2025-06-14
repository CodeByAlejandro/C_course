#include <stdio.h>

int main(int argc, char **argv) {
	float hoursWorked = 0;
	float grossPay = 0;
	float netPay = 0;
	float taxes = 0;

	printf("Enter weekly hours worked: ");
	scanf("%f", &hoursWorked);
	

	if (hoursWorked > 0 && hoursWorked <= 40) {
		grossPay = hoursWorked * 12.00f;
	} else if (hoursWorked > 40) {
		grossPay = 40 * 12.00f + (hoursWorked - 40) * 12.00f * 1.5;
	}
	
	taxes += (grossPay > 300 ? 300 : grossPay) * 0.15;

	if (grossPay > 300) {
		double grossPayAbove300 = grossPay - 300;
		taxes += (grossPayAbove300 > 150 ? 150 : grossPayAbove300) * 0.20;
	}

	if (grossPay > 450) {
		taxes += (grossPay - 450) * 0.25;
	}
	
	netPay = grossPay - taxes;
	
	printf("Your weekly payment:\n");
	printf("\tGross pay: \t%.3f\n", grossPay);
	printf("\tTaxes: \t\t%.3f\n", taxes);
	printf("\tNet pay: \t%.3f\n", netPay);
	printf("\n");

	return 0;
}