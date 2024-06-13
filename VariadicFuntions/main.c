#include <stdio.h>
#include <stdarg.h>

#define INT_LOW_VALUE 1 << ((sizeof(int) * 8) - 1)

double sumDividedByMax(int count, ...);

int main(int argc, char **argv)
{
    double sumDividedByMaxVal = sumDividedByMax(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("Sum of numbers divided by max of the numbers is %lf\n", sumDividedByMaxVal);
    return 0;
}

double sumDividedByMax(int count, ...) {
    int sum = 0;
    
    va_list pVargs, pCpyVargs;
    va_start(pVargs, count);
    va_copy(pCpyVargs, pVargs);
    for (int i = 0; i < count; i++) {
        sum += va_arg(pVargs, int);
    }
    va_end(pVargs);
    
    int max = INT_LOW_VALUE; // Set max to minimum number
    for (int i = 0, value; i < count; i++) {
        value = va_arg(pCpyVargs, int);
        if (value > max)
            max = value;
    }
    va_end(pCpyVargs);
    
    return (double) sum / max;
}
