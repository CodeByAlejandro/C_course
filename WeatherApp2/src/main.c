#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	float rainfall[5][12] = {
		{ 7.3, 7.3, 4.9, 3.0, 2.3, 0.6, 1.2, 0.3, 0.5, 1.7, 3.6, 6.7 },
		{ 9.6, 5.4, 3.2, 1.8, 2.4, 9.3, 8.7, 7.5, 6.4, 3.2, 1.7, 5.6 },
		{ 10.7, 2.7, 3.9, 4.2, 9.6, 7.5, 4.3, 1.7, 6.5, 9.3, 4.3, 2.3 },
		{ 5.9, 7.3, 6.5, 4.7, 3.2, 1.8, 3.2, 8.9, 6.4, 9.3, 11.0, 2.3 },
		{ 4.2, 8.9, 7.3, 6.3, 5.4, 6.7, 9.3, 1.7, 2.4, 5.3, 3.5, 7.6 }
	};

	printf("YEAR\tRAINFALL\n");
	int year = 2010;
	float totalRain = 0.0;
	for (int i = 0; i < 5; i++) {
		float yearlyTotal = 0.0;
		for (int j = 0; j < 12; j++) {
			yearlyTotal += rainfall[i][j];
		}
		totalRain += yearlyTotal;
		printf("%d\t%.2f\n", year++, yearlyTotal);
	}
	
	float yearlyAvg = totalRain / 5;
	printf("\nThe yearly average is %.2f inches.\n\n", yearlyAvg);

	printf("MONTHLY AVERAGES:\n\n");
	printf("Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");
	for (int j = 0; j < 12; j++) {
		float monthlyAvg = 0.0;
		for (int i = 0; i < 5; i++) {
			monthlyAvg += rainfall[i][j];
		}
		monthlyAvg /= 5;
		printf("%.2f\t", monthlyAvg);
	}

	printf("\n\n");
	return 0;
}