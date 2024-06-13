#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>

int main() {
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of signed char: %zu bytes\n", sizeof(signed char));
    printf("Size of unsigned char: %zu bytes\n", sizeof(unsigned char));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf("Size of _Bool: %zu bytes\n", sizeof(_Bool));
    printf("Size of bool: %zu bytes\n", sizeof(bool));

    printf("Range of int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of long long: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Minimum positive value of float: %e\n", FLT_MIN);
    printf("Maximum positive value of float: %e\n", FLT_MAX);
    printf("Precision of float: %d digits\n", FLT_DIG);
    printf("Minimum positive value of double: %e\n", DBL_MIN);
    printf("Maximum positive value of double: %e\n", DBL_MAX);
    printf("Precision of double: %d digits\n", DBL_DIG);
    printf("Minimum positive value of long double: %Le\n", LDBL_MIN);
    printf("Maximum positive value of long double: %Le\n", LDBL_MAX);
    printf("Precision of long double: %d digits\n", LDBL_DIG);

    return 0;
}