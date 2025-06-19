#include <stdio.h>

int strLength(const char * pString);

int main(int argc, char **argv) {
	char str1[] = "Alejandro";
	char str2[] = "A";
	char str3[] = "";
	printf("The length of str1 is %d\n", strLength(str1));
	printf("The length of str2 is %d\n", strLength(str2));
	printf("The length of str3 is %d\n", strLength(str3));

	return 0;
}

int strLength(const char * pString) {
	const char * const pStartStr = pString;
	for (; *pString; pString++);
	return pString - pStartStr;
}