#include "str_funcs_arrays.h"

int strLenArrays(const char string[]) {
	int length = 0;
	for (int i = 0; string[i] != '\0'; i++, length++);
	return length;
}

void strCatArrays(char result[], const char string1[], const char string2[]) {
	int i = 0;
	for (int j = 0; string1[j] != '\0'; i++, j++) {
		result[i] = string1[j];
	}	
	for (int j = 0; string2[j] != '\0'; i++, j++) {
		result[i] = string2[j];
	}
	result[i] = '\0';
}

bool strCmpArrays(const char string1[], const char string2[]) {
	int i = 0;
	for (; string1[i] == string2[i] && string1[i] != '\0' && string2[i] != '\0'; i++);
	return string1[i] == string2[i];
}

void testStringFunctionsArrays(void) {
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
	printf("Testing strLenArrays function\n");
	printf("-----------------------\n");
	printf("The length of the string \"%s\" is %d.\n", str1, strLenArrays(str1));
	printf("The length of the string \"%s\" is %d.\n", str2, strLenArrays(str2));
	printf("The length of the string \"%s\" is %d.\n", str9, strLenArrays(str9));
	printf("The length of the string \"%s\" is %d.\n", str8, strLenArrays(str8));
	
	/* Testing strCat function */
	printf("\nTesting strCmpArrays function\n");
	printf("-----------------------\n");
	strCatArrays(result, str3, str4);
	printf("The result of concatenating \"%s\" and \"%s\" is \"%s\".\n", str3, str4, result);

	/* Testing strCmp function */
	printf("\nTesting strCatArrays function\n");
	printf("-----------------------\n");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str1, str3, strCmpArrays(str1, str3) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str3, str1, strCmpArrays(str3, str1) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str1, str5, strCmpArrays(str1, str5) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str6, str7, strCmpArrays(str6, str7) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str7, str8, strCmpArrays(str7, str8) ? "equal" : "not equal");
	printf("The strings \"%s\" and \"%s\" are %s.\n", str6, str9, strCmpArrays(str6, str9) ? "equal" : "not equal");
	
	printf("\n");
}