#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	long minutes = 0;
    printf("Enter a number of minutes : ");
    scanf("%ld", &minutes);
    
    long double minutesInYear = 60 * 24 * 365.25;
    long double years = minutes / minutesInYear;
    long double days = minutes / (60.0L * 24); // division only works as precise as the most precise type (implicit conversion works that way)
    double daysRemainder = ((years - (long) years) * minutesInYear) / (60 * 24);
    
    printf("\nThere are %Lf minutes in a year\n", minutesInYear);
    printf("%ld minutes is %Lf years\n", minutes, years);
    printf("%ld minutes is %Lf days\n", minutes, days);
    printf("%ld minutes is %ld years and %f days\n", minutes, (long) years, daysRemainder);
    
	return 0;
}
