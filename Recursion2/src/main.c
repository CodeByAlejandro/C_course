#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursiveSumUpToN(int n);
int gcd(int num1, int num2);
char * revstr(char * str, size_t strlen, size_t idx);

int main(int argc, char **argv) {
	printf("The sum of the numbers from 1 to %d is %d\n", 5, recursiveSumUpToN(5));
	printf("GCD of %d and %d is: %d\n", 10, 50, gcd(10,50));
	printf("GCD of %d and %d is: %d\n", 27, 81, gcd(36,60));
	
	char str[] = "Alejandro De Groote";
	char rstr[20];
	strcpy(rstr, str);
	printf("The string \"%s\" in reverse is \"%s\"\n", str, revstr(rstr, strlen(rstr), 0));

	printf("\n");
	return 0;
}

int recursiveSumUpToN(int n) {
	if(n == 1)
		return 1;
	return n + recursiveSumUpToN(n - 1);
}

int gcd(int num1, int num2) {
	int remainder = num1 % num2;
	if(remainder == 0)
		return num2;
	else
		return gcd(num2, remainder);
}

char * revstr(char * str, size_t strlen, size_t startIdx) {
	size_t endIdx = (strlen - 1) - startIdx;
	if(endIdx <= startIdx) {
		return str;
	} else {
		// Swap chars at start and end indexes
		str[startIdx] ^= str[endIdx];
		str[endIdx] ^= str[startIdx];
		str[startIdx] ^= str[endIdx];
		// Recurse inward into the string
		return revstr(str, strlen, ++startIdx);
	}
}