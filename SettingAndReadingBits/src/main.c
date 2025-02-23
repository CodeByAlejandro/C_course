#include <stdio.h>

# define HIGHEST_BIT sizeof(int) * 8

int main(int argc, char **argv)
{
    // Retrieve a number
	int number;
    printf("Enter any number: ");
    scanf("%d", &number);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    // Retrieve nth bit to check and set
    unsigned char nthBit = 0;
    do {
        printf("Enter nth bit to check and set (left to right) [1-%lu]: ", HIGHEST_BIT);
        scanf("%hhu", &nthBit);
        for (char c; (c = getchar()) != '\n' && c != EOF;);
    } while (nthBit < 1 || nthBit > HIGHEST_BIT);
    
    // Check bit to set
    _Bool bitValue = number & (1 << (nthBit - 1));
    printf("The %hhu bit is set to %hhu\n\n", nthBit, bitValue);
    
    // Set bit
    int afterNumber = number | (1 << (nthBit - 1));
    printf("Bit set successfully\n\n");
    
    printf("Number before setting %hhu bit: %d (in decimal)\n", nthBit, number);
    printf("Number after setting %hhu bit: %d (in decimal)\n", nthBit, afterNumber);
	return 0;
}