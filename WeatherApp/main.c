#include <stdio.h>

int main(int argc, char **argv)
{
    float rainfall[5][12] = {
        { 0.3, 4.5, 6.2, 8.0, 5.1, 2.6, 1.7, 2.9, 3.7, 4.2, 6.0, 7.1 },
        { 0.2, 3.5, 9.0, 5.6, 3.2, 1.7, 2.9, 7.6, 4.2, 3.0, 5.6, 2.9 },
        { 0.1, 3.2, 4.9, 6.7, 3.9, 2.0, 2.0, 5.8, 6.7, 3.3, 2.2, 5.0 },
        { 4.3, 5.6, 0.5, 6.8, 1.2, 3.4, 5.6, 9.0, 6.7, 2.5, 3.4, 5.7 },
        { 2.3, 3.6, 7.8, 9.3, 4.5, 7.9, 1.3, 0.5, 2.3, 5.7, 8.0, 2.5 }
    };
    int yearIndicators[5] = { 2019, 2020, 2021, 2022, 2023 };
    
    float yearlyAverage = 0.0;
    float monthlyAverages[12] = { 0.0 };
    
    printf("YEAR   RAINFALL (inches)\n");
    for (int i = 0; i < 5; i++) {
        float yearTotal = 0.0;
        for (int j = 0; j < 12; j++) {
            yearTotal += rainfall[i][j];
            monthlyAverages[j] += rainfall[i][j];
        }
        yearlyAverage += yearTotal;
        printf("%-10d%.1f\n", yearIndicators[i], yearTotal);
    }
    yearlyAverage /= 5;
    for (int i = 0; i < 12; i++) {
        monthlyAverages[i] /= 5;
    }
    printf("\nThe yearly average is %.1f inches.\n", yearlyAverage);
    printf("\nMONTHLY AVERAGES:\n");
    printf("\nJan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
    for (int i = 0; i < 12; i++) {
        i == 11 ? printf("%-4.1f\n", monthlyAverages[i]) : printf("%-4.1f", monthlyAverages[i]);
    }
	return 0;
}
