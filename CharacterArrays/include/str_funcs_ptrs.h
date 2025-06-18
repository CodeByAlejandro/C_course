#ifndef STR_FUNCS_PTRS_H
#define STR_FUNCS_PTRS_H

#include <stdio.h>
#include <stdbool.h>

int strLen(const char * string);
void strCat(char * result, const char * string1, const char * string2);
bool strCmp(const char * string1, const char * string2);

void testStringFunctions(void);

#endif // STR_FUNCS_PTRS_H