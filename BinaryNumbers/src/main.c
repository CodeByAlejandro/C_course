#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int convertBinaryToDecimal(long long bin);
long long convertDecimalToBinary(int decimal);

int convertBinaryStrToDecimal(const char * restrict pBin, long long * decimal);
int convertDecimalToBinaryStr(long long decimal, char * restrict pBin, size_t n);

int main(int argc, char **argv) {
	printf("0     binary is %2d decimal\n", convertBinaryToDecimal(0));     // 0
	printf("101   binary is %2d decimal\n", convertBinaryToDecimal(101));   // 5
	printf("11111 binary is %2d decimal\n", convertBinaryToDecimal(11111)); // 31
	printf("+1011 binary is %2d decimal\n", convertBinaryToDecimal(+1011)); // 11
	printf("-1011 binary is %2d decimal\n", convertBinaryToDecimal(-1011)); // -5
	printf("-101  binary is %2d decimal\n", convertBinaryToDecimal(-101));  // -3
	printf("-1111 binary is %2d decimal\n", convertBinaryToDecimal(-1111)); // -1

	printf("0  decimal is %5lld binary\n", convertDecimalToBinary(0));  // 0
	printf("5  decimal is %5lld binary\n", convertDecimalToBinary(5));  // 101
	printf("31 decimal is %5lld binary\n", convertDecimalToBinary(31)); // 11111
	printf("11 decimal is %5lld binary\n", convertDecimalToBinary(11)); // 1011
	printf("-5 decimal is %5lld binary\n", convertDecimalToBinary(-5)); // -1011
	printf("-3 decimal is %5lld binary\n", convertDecimalToBinary(-3)); // -101
	printf("-1 decimal is %5lld binary\n", convertDecimalToBinary(-1)); // -11

	printf("\n");

	char binaryStr[100];
	long long decimal;

	strcpy(binaryStr, "0");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);
	}
	printf("0      binary is %2lld decimal\n", decimal); // 0
	strcpy(binaryStr, "00101");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);		
	}
	printf("00101  binary is %2lld decimal\n", decimal); // 5
	strcpy(binaryStr, "011111");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);		
	}
	printf("011111 binary is %2lld decimal\n", decimal); // 31
	strcpy(binaryStr, "01011");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);		
	}
	printf("01011  binary is %2lld decimal\n", decimal); // 11
	strcpy(binaryStr, "0000101111100001111001100100100101010");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);		
	}
	printf("0000101111100001111001100100100101010 binary is %lld decimal\n", decimal); // ??
	strcpy(binaryStr, "1011");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);		
	}
	printf("1011   binary is %2lld decimal\n", decimal); // -5
	strcpy(binaryStr, "101");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);		
	}
	printf("101    binary is %2lld decimal\n", decimal); // -3
	strcpy(binaryStr, "11");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);		
	}
	printf("11     binary is %2lld decimal\n", decimal); // -1
	strcpy(binaryStr, "1111");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);		
	}
	printf("1111   binary is %2lld decimal\n", decimal); // -1

	strcpy(binaryStr, "01013");
	if(convertBinaryStrToDecimal(binaryStr, &decimal)) {
		fprintf(stderr, "The provided string \"%s\" is not a valid binary number!\n", binaryStr);		
	}
	
	char binaryStr2[65];

	decimal = 0;
	if(convertDecimalToBinaryStr(decimal, binaryStr2, 65)) {
		fprintf(stderr, "The provided string is not large enough to store the binary number\n");
	}
	printf("0  decimal is %6s binary\n", binaryStr2);  // 0
	decimal = 5;
	if(convertDecimalToBinaryStr(decimal, binaryStr2, 65)) {
		fprintf(stderr, "The provided string is not large enough to store the binary number\n");
	}
	printf("5  decimal is %6s binary\n", binaryStr2);  // 0101
	decimal = 31;
	if(convertDecimalToBinaryStr(decimal, binaryStr2, 65)) {
		fprintf(stderr, "The provided string is not large enough to store the binary number\n");
	}
	printf("31 decimal is %6s binary\n", binaryStr2);  // 011111
	decimal = 11;
	if(convertDecimalToBinaryStr(decimal, binaryStr2, 65)) {
		fprintf(stderr, "The provided string is not large enough to store the binary number\n");
	}
	printf("11 decimal is %6s binary\n", binaryStr2);  // 01011
	decimal = -5;
	if(convertDecimalToBinaryStr(decimal, binaryStr2, 65)) {
		fprintf(stderr, "The provided string is not large enough to store the binary number\n");
	}
	printf("-5 decimal is %6s binary\n", binaryStr2);  // 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111011
	decimal = -3;
	if(convertDecimalToBinaryStr(decimal, binaryStr2, 65)) {
		fprintf(stderr, "The provided string is not large enough to store the binary number\n");
	}
	printf("-3 decimal is %6s binary\n", binaryStr2);  // 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111101
	decimal = -1;
	if(convertDecimalToBinaryStr(decimal, binaryStr2, 65)) {
		fprintf(stderr, "The provided string is not large enough to store the binary number\n");
	}
	printf("-1 decimal is %6s binary\n", binaryStr2);  // 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111

	char binaryStr3[64];
	decimal = -1;
	if(convertDecimalToBinaryStr(decimal, binaryStr3, 64)) {
		fprintf(stderr, "The provided string is not large enough to store the binary number\n");
	}

	printf("\n");
	return 0;
}

int convertBinaryToDecimal(long long bin) {
	_Bool positiveSign = bin >= 0;
	bin = positiveSign ? bin : -bin; // Invert neg binary nbrs to pos to not break > 0 in while loop below
	int decimal = 0;
	int currPowOf2 = 1; 
	do {
		_Bool leastSignificantBit = positiveSign ? bin % 2 : !(bin % 2); // Count zero's in neg binary numbers
		decimal += currPowOf2 * leastSignificantBit;
		currPowOf2 *= 2;
	} while((bin /= 10) > 0);
	if(!positiveSign) {
		decimal++; // Add 1 to the nbr of zeroes in neg binary numbers
		decimal = -decimal; // Invert nbr of zeroes + 1 in neg binary numbers
	}
	return decimal;
}

long long convertDecimalToBinary(int decimal) {
	_Bool positiveSign = decimal >= 0;
	decimal = positiveSign ? decimal : -decimal; // Invert neg binary nbrs to pos to not break > 0 in while loop below
	long long bin = 0;
	int currPowOf10 = 1; 
	do {
		_Bool leastSignificantBit = positiveSign ? decimal % 2 : !(decimal % 2); // Invert logic for neg sign nbrs
		bin += currPowOf10 * leastSignificantBit;
		currPowOf10 *= 10;
	} while((decimal /= 2) > 0);
	if(!positiveSign) {
		bin++; // Correct for extra neg nbr in range of 2's complement
		bin += currPowOf10; // Add neg sign bit
		bin = -bin; // Make bin neg
	}
	return bin;
}

int convertBinaryStrToDecimal(const char * restrict pBin, long long * decimal) {
	const char * const pBinStart = pBin;
	*decimal = 0;
	bool positiveSign;
	long long currPowOf2 = 1;
	size_t nbrOfBits = strlen(pBin);

	// Handle special cases with 0 or 1 bit given
	if(nbrOfBits == 0) {
		return 1;
	} else if(nbrOfBits == 1) {
		if(*pBin == '0') {
			return 0;
		} else if(*pBin == '1') {
			*decimal = 1;
			return 0;
		} else if(*pBin != '0' && *pBin != '1') {
			return 1;
		}
	}

	// Set highest power of 2 in binary number
	size_t times2 = strlen(pBin) - 2; // subract sign bit and least significant bit
	for(int i = 0; i < times2; i++) {
		currPowOf2 *= 2;
	}

	// Loop string
	for(; *pBin; pBin++) {
		if(*pBin != '0' && *pBin != '1') { // Check for valid binary number
			return 1;
		}
		if(pBin == pBinStart) { // Process first bit as sign
			positiveSign = *pBin == '0' ? true : false;
			continue;
		}
		if((positiveSign && *pBin == '1') || (!positiveSign && *pBin == '0')) { // Count 1's after sign for pos nbrs and 0's for neg numbers
			*decimal += currPowOf2;
		}
		currPowOf2 /= 2; // Decrease power of 2 for next rank in binary number
		if(currPowOf2 == 0) {
			currPowOf2 = 1; // Make sure we end with 1 for 2^0
		}
	}
	
	if(!positiveSign) {
		(*decimal)++; // Correct for extra neg binary number in 2's complement
		*decimal = -(*decimal); // Make sign of decimal number neg in case binary nbr is neg
	}
	
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