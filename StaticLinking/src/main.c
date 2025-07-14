#include <stdio.h>
#include "string_functions.h"

void tstCountCharInString(void);
void tstRemoveNonAlphabeticChars(void);
void tstLengthOfString(void);
void tstStrConcat(void);
void tstStrCopy(void);
void tstSubstring(void);

int main(int argc, char **argv) {
	tstCountCharInString();
	tstRemoveNonAlphabeticChars();
	tstLengthOfString();
	tstStrConcat();
	tstStrCopy();
	tstSubstring();

	printf("\n");
	return 0;
}

void tstCountCharInString(void) {
	char * str =  "Alejandro De Groote is niet voor Omer bier!";
	char chr = 'o';
	size_t cnt = countCharInString(str, chr);
	printf("Number of %c's in \"%s\" is %zd\n", chr, str, cnt);
	
	chr = 'x';
	cnt = countCharInString(str, chr);
	printf("Number of %c's in \"%s\" is %zd\n", chr, str, cnt);
	
	str = "";
	cnt = countCharInString(str, chr);
	printf("Number of %c's in \"%s\" is %zd\n", chr, str, cnt);
}

void tstRemoveNonAlphabeticChars(void) {
	char str[] = "Alejandro De Groote 1234!@#$%^&*()_+";
	printf("Original string: \"%s\"\n", str);
	removeNonAlphabeticChars(str);
	printf("Modified string: \"%s\"\n", str);
	
	str[0] = '\0'; // Reset string for next test
	printf("Original string: \"%s\"\n", str);
	removeNonAlphabeticChars(str);
	printf("Modified string: \"%s\"\n", str);
}

void tstLengthOfString(void) {
	char * str = "Alejandro De Groote";
	size_t len = lengthOfString(str);
	printf("Length of \"%s\" is %zd\n", str, len);
	
	str = "";
	len = lengthOfString(str);
	printf("Length of \"%s\" is %zd\n", str, len);
}

void tstStrConcat(void) {
	char dest[14] = "Hello, ";
	const char * source = "World!";
	printf("Before concatenation: \"%s\"\n", dest);
	strConcat(dest, source, sizeof(dest) - lengthOfString(dest));
	printf("After concatenation: \"%s\"\n", dest);
	
	char dest2[14] = "Hello, ";
	source = "this is a test.";
	printf("Before second concatenation: \"%s\"\n", dest2);
	strConcat(dest2, source, sizeof(dest2) - lengthOfString(dest2));
	printf("After second concatenation: \"%s\"\n", dest2);
}

void tstStrCopy(void) {
	char dest[14] = { '\0' }; // Initialize with null terminator
	const char * source = "Hello, World!";
	printf("Before copy: \"%s\"\n", dest);
	strCopy(dest, source, sizeof(dest) - lengthOfString(dest));
	printf("After copy: \"%s\"\n", dest);
	
	char dest2[14] = { '\0' }; // Initialize with null terminator
	source = "Hello, this is a test.";
	printf("Before second copy: \"%s\"\n", dest2);
	strConcat(dest2, source, sizeof(dest2) - lengthOfString(dest2));
	printf("After second copy: \"%s\"\n", dest2);
}

void tstSubstring(void) {
	char target[20];
	const char * source = "Hello, World!";
	int result = substring(target, 7, 5, source);
	if(result == 0) {
		printf("Substring from index 7 with length 5: \"%s\"\n", target);
	} else {
		printf("Error in substring operation: %d\n", result);
	}
	
	result = substring(target, 0, 5, source);
	if(result == 0) {
		printf("Substring from index 0 with length 5: \"%s\"\n", target);
	} else {
		printf("Error in substring operation: %d\n", result);
	}
	
	result = substring(target, 13, 1, source); // Out of bounds
	if(result != 0) {
		printf("Error in substring operation (expected): %d\n", result);
	}
	
	result = substring(target, 0, 20, source); // Length exceeds source
	if(result != 0) {
		printf("Error in substring operation (expected): %d\n", result);
	}
}