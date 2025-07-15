#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

static void tstCountCharInString(void);
static void tstRemoveNonAlphabeticChars(void);
static void tstLengthOfString(void);
static void tstStrConcat(void);
static void tstStrCopy(void);
static void tstSubstring(void);

static void * dynamicLoadFuncs(void);
static void chkDlsymError(void);
static void closeHandle(void * handle);

static size_t (*countCharInString)(const char * restrict str, char chr) = NULL;
static char * (*removeNonAlphabeticChars)(char * restrict str) = NULL;
static size_t (*lengthOfString)(const char * restrict str) = NULL;
static char * (*strConcat)(char * restrict dest, const char * restrict source, size_t n) = NULL;
static char * (*strCopy)(char * restrict dest, const char * restrict source, size_t n) = NULL;
static int (*substring)(char * restrict target, size_t from, size_t n, const char * restrict source) = NULL;

int main(int argc, char **argv) {
	void * handle = NULL;

	handle = dynamicLoadFuncs();

	tstCountCharInString();
	tstRemoveNonAlphabeticChars();
	tstLengthOfString();
	tstStrConcat();
	tstStrCopy();
	tstSubstring();
	
	closeHandle(handle);

	printf("\n");
	return 0;
}

static void * dynamicLoadFuncs(void) {
	void * handle = NULL;

	handle = dlopen("./libstring_functions.so", RTLD_LAZY);
	if(handle == NULL) {
		fputs(dlerror(), stderr);
		exit(1);
	}
	dlerror(); // Clear errors

	countCharInString = (size_t (*)(const char * restrict, char)) dlsym(handle, "countCharInString");
	chkDlsymError();
	removeNonAlphabeticChars = (char * (*)(char * restrict)) dlsym(handle, "removeNonAlphabeticChars");
	chkDlsymError();
	lengthOfString = (size_t (*)(const char * restrict)) dlsym(handle, "lengthOfString");
	chkDlsymError();
	strConcat = (char * (*)(char * restrict, const char * restrict, size_t)) dlsym(handle, "strConcat");
	chkDlsymError();
	strCopy = (char * (*)(char * restrict, const char * restrict, size_t)) dlsym(handle, "strCopy");
	chkDlsymError();
	substring = (int (*)(char * restrict, size_t, size_t, const char * restrict)) dlsym(handle, "substring");
	chkDlsymError();
	
	return handle;
}

static void chkDlsymError(void) {
	char * error = NULL;

	if((error = dlerror()) != NULL) {
		fputs(error, stderr);
		exit(1);
	}
	dlerror(); // Clear errors
}

static void closeHandle(void * handle) {
	if(dlclose(handle) != 0) {
		fputs(dlerror(), stderr);
		exit(1);
	}
	dlerror();
}

static void tstCountCharInString(void) {
	char * str =  "Alejandro De Groote is niet voor Omer bier!";
	char chr = 'o';
	size_t cnt = (*countCharInString)(str, chr);
	printf("Number of %c's in \"%s\" is %zd\n", chr, str, cnt);
	
	chr = 'x';
	cnt = (*countCharInString)(str, chr);
	printf("Number of %c's in \"%s\" is %zd\n", chr, str, cnt);
	
	str = "";
	cnt = (*countCharInString)(str, chr);
	printf("Number of %c's in \"%s\" is %zd\n", chr, str, cnt);
}

static void tstRemoveNonAlphabeticChars(void) {
	char str[] = "Alejandro De Groote 1234!@#$%^&*()_+";
	printf("Original string: \"%s\"\n", str);
	(*removeNonAlphabeticChars)(str);
	printf("Modified string: \"%s\"\n", str);
	
	str[0] = '\0'; // Reset string for next test
	printf("Original string: \"%s\"\n", str);
	(*removeNonAlphabeticChars)(str);
	printf("Modified string: \"%s\"\n", str);
}

static void tstLengthOfString(void) {
	char * str = "Alejandro De Groote";
	size_t len = (*lengthOfString)(str);
	printf("Length of \"%s\" is %zd\n", str, len);
	
	str = "";
	len = (*lengthOfString)(str);
	printf("Length of \"%s\" is %zd\n", str, len);
}

static void tstStrConcat(void) {
	char dest[14] = "Hello, ";
	const char * source = "World!";
	printf("Before concatenation: \"%s\"\n", dest);
	(*strConcat)(dest, source, sizeof(dest) - (*lengthOfString)(dest));
	printf("After concatenation: \"%s\"\n", dest);
	
	char dest2[14] = "Hello, ";
	source = "this is a test.";
	printf("Before second concatenation: \"%s\"\n", dest2);
	(*strConcat)(dest2, source, sizeof(dest2) - (*lengthOfString)(dest2));
	printf("After second concatenation: \"%s\"\n", dest2);
}

static void tstStrCopy(void) {
	char dest[14] = { '\0' }; // Initialize with null terminator
	const char * source = "Hello, World!";
	printf("Before copy: \"%s\"\n", dest);
	(*strCopy)(dest, source, sizeof(dest) - (*lengthOfString)(dest));
	printf("After copy: \"%s\"\n", dest);
	
	char dest2[14] = { '\0' }; // Initialize with null terminator
	source = "Hello, this is a test.";
	printf("Before second copy: \"%s\"\n", dest2);
	(*strCopy)(dest2, source, sizeof(dest2) - (*lengthOfString)(dest2));
	printf("After second copy: \"%s\"\n", dest2);
}

static void tstSubstring(void) {
	char target[20];
	const char * source = "Hello, World!";
	int result = (*substring)(target, 7, 5, source);
	if(result == 0) {
		printf("Substring from index 7 with length 5: \"%s\"\n", target);
	} else {
		printf("Error in substring operation: %d\n", result);
	}
	
	result = (*substring)(target, 0, 5, source);
	if(result == 0) {
		printf("Substring from index 0 with length 5: \"%s\"\n", target);
	} else {
		printf("Error in substring operation: %d\n", result);
	}
	
	result = (*substring)(target, 13, 1, source); // Out of bounds
	if(result != 0) {
		printf("Error in substring operation (expected): %d\n", result);
	}
	
	result = (*substring)(target, 0, 20, source); // Length exceeds source
	if(result != 0) {
		printf("Error in substring operation (expected): %d\n", result);
	}
}