#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isEven(int number);
bool isPrime(int number);

int main(int argc, char **argv)
{
    FILE *fp = fopen("numbers.txt", "r");
    if (!fp) {
        fprintf(stderr, "Could not open file for reading!\n");
        exit(EXIT_FAILURE);
    }
    for (int number; fscanf(fp, "%d", &number) == 1;) {
        if (isPrime(number))
            printf("Prime number found: %d\n", number);
        else if (isEven(number))
            printf("Even number found: %d\n", number);
        else
            printf("Odd number found: %d\n", number);
    }
    if (ferror(fp)) {
        fprintf(stderr, "An error occurred while trying to read number from file!\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    return 0;
}

bool isEven(int number) {
    return number % 2 == 0;
}

bool isPrime(int number) {
    if (number < 0)
        return 0;
    for (int i=2; (double) number/i > i; i++)
        if (number % i == 0)
            return 0;
    return 1;
}