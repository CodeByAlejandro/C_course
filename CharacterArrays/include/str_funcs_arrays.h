#ifndef STR_FUNCS_ARRAYS_H
#define STR_FUNCS_ARRAYS_H

#include <stdio.h>
#include <stdbool.h>

int strLenArrays(const char string[]);
void strCatArrays(char result[], const char string1[], const char string2[]);
bool strCmpArrays(const char string1[], const char string2[]);

void testStringFunctionsArrays(void);

#endif // STR_FUNCS_ARRAYS_H