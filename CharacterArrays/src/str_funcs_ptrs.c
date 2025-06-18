#include "str_funcs_ptrs.h"

int strLen(const char * charPtr) {
	int length = 0;
	for (; *charPtr++ != '\0'; length++);
	return length;
}

void strCat(char * resultPtr, const char * charPtr1, const char * charPtr2) {
	for (; *charPtr1 != '\0'; *resultPtr++ = *charPtr1++);
	for (; *charPtr2 != '\0'; *resultPtr++ = *charPtr2++);
	*resultPtr = '\0';
}

bool strCmp(const char * charPtr1, const char * charPtr2) {
	for (; *charPtr1 == *charPtr2 && *charPtr1 != '\0' && *charPtr2 != '\0'; charPtr1++, charPtr2++);
	return *charPtr1 == *charPtr2;
}

void testStringFunctions(void) {
	char result[24];
	char str1[] = "Alejandro is learning C";
	char str2[] = "Alejandro\0 is learning C";
	char str3[] = "Alejandro";
	char str4[] = " is learning C";
	char str5[] = "Alejandro is learning C";
	char str6[] = "A";
	char str7[] = "B";
	char str8[] = "\0";
	char str9[] = "A\0";

	/* Testing strLen function */
	printf("Testing strLen function\n");
	printf("-----------------------\n");
	printf("The length of the string \"%s\" is %d.\n", str1, strLen(str1));
	printf("The length of the string \"%s\" is %d.\n", str2, strLen(str2));
	printf("The length of the string \"%s\" is %d.\n", str9, strLen(str9));
	printf("The length of the string \"%s\" is %d.\n", str8, strLen(str8));
	
	/* Testing strCat function */
	printf("\nTesting strCmp function\n");
	printf("-----------------------\n");
	strCat(result, str3, str4);
	printf("The result of concatenating \"%s\" and \"%s\" is \"%s\".\n", str3, str4, result);

	/* Testing strCmp function */
	printf("\nTesting strCat function\n");
	printf("-----------------------\n");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str1, str3, strCmp(str1, str3) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str3, str1, strCmp(str3, str1) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str1, str5, strCmp(str1, str5) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str6, str7, strCmp(str6, str7) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str7, str8, strCmp(str7, str8) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str6, str9, strCmp(str6, str9) ? "equal" : "not equal");
	
	printf("\n");
}