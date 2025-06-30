#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int convertDecimalToBinaryStr(long long decimal, char * restrict pBin, size_t n);

int main(int argc, char **argv) {
	long long num1 = 0;
	long long num2 = 0;
	long long num3 = 0;
	char binaryStr1[65];
	char binaryStr2[65];
	char binaryStr3[65];

	printf("Enter an integer: ");
	scanf("%lld", &num1);
	printf("Enter another integer: ");
	scanf("%lld", &num2);
	
	printf("\n");

	convertDecimalToBinaryStr(num1, binaryStr1, 65);
	convertDecimalToBinaryStr(num2, binaryStr2, 65);

	num3 = ~num1;
	convertDecimalToBinaryStr(num3, binaryStr3, 65);
	printf("The result of applying the ~ operator on number %lld (%s) is: %lld (%s)\n",
		 num1, binaryStr1, num3, binaryStr3);
		
	num3 = ~num2;
	convertDecimalToBinaryStr(num3, binaryStr3, 65);
	printf("The result of applying the ~ operator on number %lld (%s) is: %lld (%s)\n",
		 num2, binaryStr2, num3, binaryStr3);

	num3 = num1 & num2;
	convertDecimalToBinaryStr(num3, binaryStr3, 65);
	printf("The result of applying the & operator on number %lld (%s) and number %lld (%s) is: %lld (%s)\n",
		 num1, binaryStr1, num2, binaryStr2, num3, binaryStr3);

	num3 = num1 | num2;
	convertDecimalToBinaryStr(num3, binaryStr3, 65);
	printf("The result of applying the | operator on number %lld (%s) and number %lld (%s) is: %lld (%s)\n",
		 num1, binaryStr1, num2, binaryStr2, num3, binaryStr3);

	num3 = num1 ^ num2;
	convertDecimalToBinaryStr(num3, binaryStr3, 65);
	printf("The result of applying the ^ operator on number %lld (%s) and number %lld (%s) is: %lld (%s)\n",
		 num1, binaryStr1, num2, binaryStr2, num3, binaryStr3);

	num3 = num1 << 2;
	convertDecimalToBinaryStr(num3, binaryStr3, 65);
	printf("The result of applying the left shift operator << on number %lld (%s) by 2 places is: %lld (%s)\n",
		 num1, binaryStr1, num3, binaryStr3);

	num3 = num1 >> 2;
	convertDecimalToBinaryStr(num3, binaryStr3, 65);
	printf("The result of applying the right shift operator >> on number %lld (%s) by 2 places is: %lld (%s)\n",
		 num1, binaryStr1, num3, binaryStr3);

	printf("\n");
	return 0;
}

int convertDecimalToBinaryStr(long long decimal, char * restrict pBin, size_t n) {
	char * const pStartBin = pBin;
	size_t nbrOfBits = sizeof(long long) * 8;
	bool positiveSign;

	if(nbrOfBits > (n - 1)) {
		return 1; // Not enough space allocated in char array
	}

	// Set bitmask for highest order bit excluding sign bit
	long long bitmask = 1;
	for(int i = 0; i < nbrOfBits - 2; i++) {
		bitmask <<= 1;
	}
	
	// Copy all bits in char array
	for(int i = 0; i < nbrOfBits; i++) {
		bool bitIsSet;
		if(i == 0) {
			// Cannot shift into sign bit or we'll shift 1's back! -> only do it in this statement but don't change the bitmask
			bitIsSet = decimal & (bitmask << 1); 
			positiveSign = bitIsSet ? false : true;
		} else {
			bitIsSet = (decimal & bitmask);
			bitmask >>= 1;
		}
		if(bitIsSet) {
			*pBin = '1';
		} else {
			*pBin = '0';
		}
		pBin++;
	}
	*pBin = '\0';
	
	// Remove leading redundant 0's / 1's
	pBin = pStartBin;
	const char * pNewBin = NULL;
	if(positiveSign) {
		pNewBin = strchr(pBin, '1');
	} else {
		pNewBin = strchr(pBin, '0');
	}
	if(pNewBin) {
		pNewBin--; // Include leading sign
		for(; *pNewBin; *pBin++ = *pNewBin++);
	} else {
		if(positiveSign) {
			*pBin = '0';
		} else {
			*pBin = '1';
			*++pBin = '1';
		}
		pBin++;
	}
	*pBin = '\0';
	
	return 0;
}