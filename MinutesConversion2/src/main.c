#include <stdio.h>
#include <stdlib.h>

#define MINUTES_IN_DAY (60 * 24)
#define MINUTES_IN_YEAR (MINUTES_IN_DAY * 365)

int main(int argc, char **argv) {
	int minutes = 0;

	// user input
	if (argc > 1) {
		char * minutesStr = argv[1]; // equal to *(++argv)
		char * endptr = NULL;
		minutes = (int) strtod(minutesStr, &endptr);
		if (*endptr != '\0') {
			fprintf(stderr, "Invalid input: %s\n", minutesStr);
			return 1;
		}
	} else {
		printf("Enter the number of minutes: ");
		scanf("%d", &minutes);
	}

	// Calculate number of years and days
	// int minutesInDay = 60 * 24;
	// int minutesInYear = minutesInDay * 365;
	double years = (double) minutes / MINUTES_IN_YEAR;
	double days = (double) minutes / MINUTES_IN_DAY;
	
	// Output the results
	printf("%d minutes is approximately %f years or %f days.\n", minutes, years, days);

	return 0;
}