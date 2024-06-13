#include <stdio.h>
#include <stdlib.h>

void testGCD(void);
unsigned int greatestCommonDivider(unsigned int number1, unsigned int number2);

void testABS(void);
double absoluteValue(double number);

void testSQRT(void);
double squareRoot(double number);

int main(int argc, char *argv[])
{
    testGCD();
    printf("\n");
    testABS();
    printf("\n");
    testSQRT();
	return 0;
}

/*
 * Function to test GCD function
 */
void testGCD(void) {
    unsigned int number1, number2, result;
    printf("Enter 2 positive integers to calculate the GCD:\n");
    printf("1> ");
    scanf("%u", &number1);
    printf("2> ");
    scanf("%u", &number2);
    result = greatestCommonDivider(number1, number2);
    printf("The GCD of %u and %u is %u\n", number1, number2, result);
}

/*
 * Function to test ABS function
 */
void testABS(void) {
    double number, result;
    printf("Enter a number to get the absolute value of: ");
    scanf("%lf", &number);
    result = absoluteValue(number);
    printf("The absolute value of %lf is %lf\n", number, result);
}

/*
 * Calculate the greatest common divider using modulus calculations.
 * The idea is that both the numbers can be written as a product of the GCD.
 * That means that when we take the modulus of one of the numbers with the other,
 * we will get a remainder that also can be written as a product of the GCD.
 * If the remainder is 0 (e.g. 81 % 9), then we found the GCD. If the remainder
 * is not 0 (e.g. 81 % 8 = 1), we need to repeat the calculation by taking the
 * modulus of the second number with the remainder again (e.g. 8 % 1 = 0).
 * If we reach a remainder of 0, we know the second number to be the GCD.
 */
unsigned int greatestCommonDivider(unsigned int number1, unsigned int number2) {
    unsigned int remainder = 0;
    while ((remainder = number1 % number2) != 0) {
        number1 = number2;
        number2 = remainder;
    }
    // alternative for while loop
    // for (unsigned int remainder = 0; (remainder = number1 % number2) != 0; number1 = number2, number2 = remainder);
    return number2;
}

/*
 * Function to calculate absolute value of a number
 */
double absoluteValue(double number) {
    return number < 0 ? -number : number;
}

/*
 * Function to test SQRT function
 */
void testSQRT(void) {
    double number, result;
    printf("Enter a number to get the square root of: ");
    scanf("%lf", &number);
    result = squareRoot(number);
    if (result < 0) {
        printf("Can't take the square root of a negative number: %lf!\n", number);
    } else {
        printf("The square root of %lf is %lf\n", number, result);
    }
}

/*
 * Function to calculate square root of a number
 * 
 * It starts by guessing at the root and placing an initial value into the equation.
 * The outcome of the equation is than used as the next guess in the same equation.
 * This we we keep calculating the recursive equation until we reach a satisfying precision.
 */
double squareRoot(double number) {
    if (number < 0)
        return -1.0;
    if (number == 0 || number == 1)
        return number;
    // Initialize first guess at the root by setting the previously calculated root to the number itself (initial value doesn't matter much).
    double guessRoot, calcRoot = number;
    /* Calculate the root more precise by using the previously calculated root as the new guess for the root calculation.
    With each iteration we calculate the average of 2 factors in the product that makes up our number, of which one factor is
    the current guessed root and the other is it's inverse factor in that product. This average should get us closer to the 
    real root each time we calculate it. We know how close we are by calculating the difference between the current guessed root
    and the calculated root that stems from using it in the equation. We are satisfied when the calculated value for the root has
    an accuracy of 5 decimals after the decimal point. */
    int cycles = 0;
    do {
        cycles++;
        guessRoot = calcRoot;
        calcRoot = (guessRoot + (number / guessRoot)) / 2; // product: guessRoot * number/guessRoot = number
    } while (absoluteValue(calcRoot-guessRoot) >= 0.00001);
    printf("Number of cycles is %d\n", cycles);
    return calcRoot;
}