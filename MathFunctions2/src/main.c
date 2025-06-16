#include <stdio.h>

unsigned int gcd(unsigned int, unsigned int);
float absl(float);
double sqrt(double);

int main(int argc, char **argv) {
	printf("gcd of 10 and 5 is: %u\n", gcd(10, 5));
	printf("gcd of 80 and 90 is: %u\n", gcd(80, 90));
	printf("absolute value of -90.5 is %.2f\n", absl(-90.5));
	printf("absolute value of 90.5 is %.2f\n", absl(90.5));
	printf("absolute value of -7 is %.2f\n", absl(-7));
	printf("absolute value of 7 is %.2f\n", absl(-7));
	printf("square root of -16 is %.2f\n", sqrt(-16));
	printf("square root of 16 is %.2f\n", sqrt(16));
	printf("square root of 7 is %f\n", sqrt(7));

	printf("\n");
	return 0;
}

unsigned int gcd(unsigned int nbr1, unsigned int nbr2) {
	for (unsigned int remainder; nbr1 % nbr2 != 0;
		 remainder = nbr1 % nbr2, nbr1 = nbr2, nbr2 = remainder);
	return nbr2;
}

float absl(float nbr) {
	if (nbr < 0)
		nbr = -nbr;
	return nbr;
}

double sqrt(double nbr) {
	if (nbr < 0) {
		printf("The number passed cannot be negative : %.2f !\n", nbr);
		return -1.0;
	}
	double sqrt = 1.0;
	for (double acc = .00001; absl(nbr / sqrt - sqrt) > acc; sqrt = (nbr / sqrt + sqrt) / 2);
	return sqrt;
}