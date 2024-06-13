#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define PRINTINT(int) printf(# int " = %i\n", (int))
#define CONCAT(x, y)  x ## y

// Notice parentheses are important for precedence after replacements in underlying macros
#define SUM(a, b) ((a) + (b))
#define PRINTF_ARGS_FOR_SUM(a, b) a, b, SUM(a, b)

#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))

#define IS_UPPER(c) (isupper(c))
#define IS_LOWER(c) (islower(c))

#define IS_UPPER2(c) (c < 97 ? true : false)
#define IS_LOWER2(c) (c >= 97 ? true : false)

// Notice a variadic macro does not need fixed parameters like a variadic function does
// They do however still need to come last
#define PRINTERR(format, ...) fprintf(stderr, format, __VA_ARGS__)

#define DECL_QSORT_FUNCS(type) \
    static int _declare_ ## type ## _compare(const void* pItem1, const void* pItem2) { \
        const type * pTypeItem1 = (const type*) pItem1; \
        const type * pTypeItem2 = (const type*) pItem2; \
        if (*pTypeItem1 > *pTypeItem2) \
            return 1; \
        else if (*pTypeItem1 < *pTypeItem2) \
            return -1; \
        else \
            return 0; \
    } \
    \
    static void _sort(type * array, size_t nbrOfElements) { \
        qsort(array, nbrOfElements, sizeof(type), _declare_ ## type ## _compare); \
    }

DECL_QSORT_FUNCS(int)


int main(int argc, char **argv)
{
    PRINTINT(argc + 1);
    printf("%d\n", CONCAT(1,5));
    
    printf("Printf function is in %s at %d\n", __FILE__, __LINE__);
    
    printf("This program was last compiled at %s on %s\n", __TIME__, __DATE__);
    
    if (__STDC__ == 1) {
        printf("This compiler is ISO-standard conforming\n");
    } else {
        printf("This compiler is NOT ISO-standard conforming\n");
    }
    
    printf("The sum of %d and %d is %d\n", 5, 10, SUM(5,10));
    printf("The sum of %d and %d is %d\n", PRINTF_ARGS_FOR_SUM(5,10));
    
    printf("The square of %d is %d\n", 5, SQUARE(5));
    printf("The cube of %d is %d\n", 5, CUBE(5));
    
    printf("The character '%c' is %scase\n", 'A', IS_UPPER('A') ? "upper" : "lower");
    printf("The character '%c' is %scase\n", 'a', IS_LOWER('a') ? "lower" : "upper");
    
    printf("The character '%c' is %scase\n", 'A', IS_UPPER2('A') ? "upper" : "lower");
    printf("The character '%c' is %scase\n", 'a', IS_LOWER2('a') ? "lower" : "upper");
    
    PRINTERR("Printing the integers %d, %d, %d to stderr!\n", 5, 10, 17);
    
    int numbers[20];
    for (int i = 0, j = 20; i < 20; i++, j--) {
        numbers[i] = j;
        printf("%d ", j);
    }
    // expands to  qsort(numbers, 20, sizeof(int), _declare_int_compare);
    _sort(numbers, 20);
    printf("\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", numbers[i]);
    }
    
    return 0;
}