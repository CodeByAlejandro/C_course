#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int requestIntToBinConv(void);
int intToBinary(int decRepr, long long * const restrict pBinReprResult);

int requestBinToIntConv(void);
int binaryToInt(long long binRepr, int * restrict decReprResult, _Bool isNegative);

int requestIntToBinStrConv(void);
int intToBinaryStr(long long int decRepr, char ** const restrict ppBinReprResult);

int requestBinStrToIntConv(void);
int binaryStrToInt(const char * restrict pBinRepr, long long int * const restrict pDecRepr);

int main(int argc, char **argv)
{
    int returnVal = 0;
    //returnVal = requestIntToBinConv();
    //returnVal = requestBinToIntConv();
    returnVal = requestIntToBinStrConv();
    returnVal = requestBinStrToIntConv();
	return returnVal;
}

int requestIntToBinConv(void) {
    // Retrieve integer number to convert to binary as long long decimal
    int decRepr = 0;
    printf("Enter an integer value between -262144 and 524287 (inclusive) to convert to binary:\n");
    scanf("%d", &decRepr);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    // Convert integer to binary as long long in decimal format
    long long binReprResult = 0LL;
    int returnVal = intToBinary(decRepr, &binReprResult);
    switch (returnVal) {
        case 0:
            printf("The binary representation of %d is %lld\n", decRepr, binReprResult);
            return 0;
        case 1:
            printf("Integer value is to large to translate into a binary as long long decimal format!\n");
            return 1;
        default:
            return returnVal;
    }
}

/*
 * Function that accepts an integer value, translates it to a variable length binary string
 * in the form of a long long decimal format and sets the result by dereferencing the accepted
 * long long pointer. The sign of the accepted integer determines the binary format.
 * In case of overflow in the long long decimal format, the return value is 1. Upon
 * success the returnvalue is 0.
 */
int intToBinary(int decRepr, long long * const restrict pBinReprResult) {
    if (decRepr < -262144 || decRepr > 524287) {
        // Overflow detected
        return 1;
    }
    
    // Convert powers of 2 to powers of 10 to build binary represenation with decimal long long
    long long binRepr = 0;
    long long pow10 = 1000000000000000000LL;
    long long leading1BitsToRemFromNegativeNbr = 0;
    _Bool firstZeroBit = 0;
    for (int pos = 18; pos >= 0; pos--, pow10 /= 10) {
        // Check bit is set on
        if (decRepr & (1 << pos)) {
            binRepr += pow10;
        // Check bit is set off
        } else {
            if (!firstZeroBit) {
                firstZeroBit = 1;
                leading1BitsToRemFromNegativeNbr = binRepr - (pow10 * 10);
            }
        }
    }
    
    // If number is -1 we have only 1s, so subtract all but the last 2 1s.
    if (!firstZeroBit) {
        leading1BitsToRemFromNegativeNbr = binRepr - 11;
    }
    
    // Correct for negative sign not counting as a power of 2
    if (decRepr & (1 << ((sizeof(int) * 8) - 1))) {
        binRepr -= leading1BitsToRemFromNegativeNbr;
    }
    
    // Set the resulting long long
    *pBinReprResult = binRepr;
    // Set returnvalue of success
    return 0;
}

int requestBinToIntConv(void) {
    // Retrieve binary number as long long
    long long binRepr;
    printf("Please enter a binary number to translate (leading zeroes are ignored):\n");
    scanf("%lld", &binRepr);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    // retrieve sign
    printf("Is this number to be interpreted as negatively signed? [Y/N] (N):\n");
    char answer = 0;
    do {
        scanf("%c", &answer);
        if (answer == '\n')
            answer = 'N';
        answer = toupper(answer);
    } while (answer != 'Y' && answer != 'N');
    _Bool isNegative = 0;
    if (answer == 'Y')
        isNegative = 1;
    
    // Convert to decimal int
    int decReprResult = 0;
	int returnVal = binaryToInt(binRepr, &decReprResult, isNegative);
    switch (returnVal) {
        case 0:
            printf("The decimal representation of %lld is %d\n", binRepr, decReprResult);
            return 0;
        case 1:
            printf(
                "Binary number is to large to store in a "
                "alalalalala long ... alalalalala long ... alalalalala long long .. long long .. long long!\n"
            );
            return 1;
        case 2:
            printf("Binary representation to translate is not correct!\n");
            return 2;
        default:
            return returnVal;
    }
}

/*
 * Function that accepts a variable length binary number formatted as a long long integer,
 * translates it to a decimal integer and sets the result by dereferencing the accepted int pointer.
 * A _Bool isNegative is accepted to indicate the binary value has to be interpreted as
 * negative as per the first 1 digit. Leading zeroes in the long long are simply ignored.
 * In case of a non binary long long input, the return value is 1. In case of
 * overflow the return value is 2. Upon success the returnvalue is 0.
 */
int binaryToInt(long long binRepr, int * const restrict pDecReprResult, _Bool isNegative) {
    if (binRepr > 1111111111111111111LL) {
        // Overflow detected
        return 1;
    }
    
    int decReprResult = 0;
    long long pow10 = 10;
    long long remainder = binRepr % pow10;
    
    // Process first binary digit in binRepr
    if (remainder > 1) {
        // Non binary digit detected
        return 2;
    } else if (remainder == 1) {
        decReprResult += 1;
    }
    
    // Process all other binary digits in binRepr
    int NbrOfBinDigits = 1;
    long pow2 = 1L << 1;
    while (binRepr / pow10 > 0) {
        long long nextPow10 = pow10 * 10;
        remainder = binRepr % nextPow10;
        if (remainder >= 2 * pow10) {
            // Non binary digit detected
            return 2;
        } else if (remainder >= pow10) {
            decReprResult |= pow2;
        }
        pow2 <<= 1;
        pow10 *= 10;
        NbrOfBinDigits++;
        if (NbrOfBinDigits == 19) {
            break;
        }
    }
    
    // Process sign if applicable
    if (isNegative && (binRepr / 10 > 0)) {
        // set int to all 1's
        int all1s = -1;
        // Calculate highest possible value for length of negative binary number (all 1's for length of number given)
        int subtractFromAll1sToSetEndingZeroes = 0;
        pow2 = 1L;
        for (int i = 0; i < NbrOfBinDigits; i++) {
            subtractFromAll1sToSetEndingZeroes |= pow2;
            pow2 <<= 1;
        }
        // Set a bitmask for the length of the return value with all 1's,
        // followed by as much zeroes as the length of the negative number
        int bitMaskToPrecResWith1s = all1s - subtractFromAll1sToSetEndingZeroes;
        // Precede the calculated result with 1's to create the correct negative value in a larger return value
        decReprResult = bitMaskToPrecResWith1s | decReprResult;
    }
    
    // Set the resulting int
    *pDecReprResult = decReprResult;
    // Set returnvalue of success
    return 0;
}

int requestIntToBinStrConv(void) {
    // Retrieve long long integer number to convert to binary as character array
    long long int decRepr = 0;
    printf("Enter a long long integer value to convert to binary:\n");
    scanf("%lld", &decRepr);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    // Convert long long integer to binary character array
    char * pBinReprResult = NULL;
    int returnVal = intToBinaryStr(decRepr, &pBinReprResult);
    switch (returnVal) {
        case 0:
            printf("The binary representation of %lld is %s\n", decRepr, pBinReprResult);
            free(pBinReprResult);
            return 0;
        case 1:
            printf("Memory allocation for variable length character array failed!\n");
            return 1;
        default:
            return returnVal;
    }
}

/*
 * Function that accepts a long long integer value, translates it to a variable length
 * binary character string and sets the result by dereferencing the accepted
 * character pointer pointer. The sign of the accepted integer determines the binary format.
 * If memory allocation for the variable length binary string fails, the return value is 1. Upon
 * success the returnvalue is 0.
 */
int intToBinaryStr(long long int decRepr, char ** const restrict ppBinReprResult) {
    // Let just start by allocating the max amount of needed memory for the binary string
    unsigned char maxMemReqInBytes = (sizeof(long long int) * 8) + 1;
    char * pBinReprResultStart = (char *) malloc(maxMemReqInBytes * sizeof(char));
    if (!pBinReprResultStart) {
        // Memory allocation failed
        return 1;
    }
    
    // Set loop pointer to start pointer
    char * pBinReprResult = pBinReprResultStart;
    
    // Start loop over bits to write the binary string to the allocated memory block
    _Bool signBit, currBit, firstBitDiffFromSignBit = 0;
    for (short int shiftAmount = sizeof(long long int) * 8 - 1; shiftAmount >= 0; shiftAmount--) {
        // Check if bit is set
        if (decRepr & (1LL << shiftAmount)) {
            // Check if it is the first bit (= sign bit)
            if (pBinReprResult == pBinReprResultStart) {
                // Write the sign bit to the binary string
                *pBinReprResult = '1';
                // Keep track of what sign bit was
                signBit = 1;
            } else {
                // Keep track of current bit but don't decide to write it to the binary string yet
                currBit = 1;
            }
        } else {
            // Check if it is the first bit (= sign bit)
            if (pBinReprResult == pBinReprResultStart) {
                // Write the sign bit to the binary string
                *pBinReprResult = '0';
                // Keep track of what sign bit was
                signBit = 0;
            } else {
                // Keep track of current bit but don't decide to write it to the binary string yet
                currBit = 0;
            }
        }
        // If we have not yet found the first bit differing from the sign bit and are currently past the sign bit itself
        if (!firstBitDiffFromSignBit && pBinReprResult != pBinReprResultStart) {
            // If we found the first bit that is not part of leading zeroes or ones that form padding
            if (currBit != signBit)
                firstBitDiffFromSignBit = 1;
        }
        // Write the current bit to the binary string if it is not leading padding
        if (firstBitDiffFromSignBit) {
            if (currBit) {
                *pBinReprResult = '1';
                pBinReprResult++;
            } else {
                *pBinReprResult = '0';
                pBinReprResult++;
            }
        } else if (pBinReprResult == pBinReprResultStart) {
            pBinReprResult++;
        }
    }
    
    // If number is -1 we have only zeroes after the sign bit, so add another 1 in the binary string
    if (signBit == 1 && firstBitDiffFromSignBit == 0) {
        *pBinReprResult = '1';
        pBinReprResult++;
    }
    
    // Write the ending null byte to the binary string
    *pBinReprResult = '\0';
    
    // Calculate the required amount of bytes to store the binary string
    // (such that we can shrink it if we reserved to much memory in the beginning)
    unsigned char totalMemReqInBytes = ((pBinReprResult - pBinReprResultStart) * sizeof(char)) + 1;
    
    // If we can store the binary string more efficient than shrinkt the corresponding memory block
    if (totalMemReqInBytes < maxMemReqInBytes) {
        char * pBinReprResultReallocated = (char *) realloc(pBinReprResultStart, totalMemReqInBytes);
        // If it succeeds, update the corresponding pointer
        if (pBinReprResultReallocated) {
            pBinReprResultStart = pBinReprResultReallocated;
        }
    }
    
    // Set the accepted char ** to point to the binary string memory block,
    // as a means of returning the binary string pointer by reference
    *ppBinReprResult = pBinReprResultStart;
    // Set returnvalue of success
    return 0;
}

int requestBinStrToIntConv(void) {
    // Retrieve binary number as string
    char binRepr[(sizeof(long long int) * 8) + 1];
    printf("Please enter a binary number to translate (first digit is sign):\n");
    scanf("%s", binRepr);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    // Convert to decimal long long int
    long long int decReprResult = 0;
	int returnVal = binaryStrToInt(binRepr, &decReprResult);
    switch (returnVal) {
        case 0:
            printf("The decimal representation of %s is %lld\n", binRepr, decReprResult);
            return 0;
        case 1:
            printf("Binary representation to translate is not correct!\n");
            return 1;
        case 2:
            printf(
                "Binary number is to large to translate into a "
                "alalalalala long ... alalalalala long ... alalalalala long long .. long long .. long long!\n"
            );
            return 2;
        default:
            return returnVal;
    }
}

/*
 * Function that accepts a variable length binary number formatted as a string, translates it
 * to a decimal long long integer and sets the result by dereferencing the accepted
 * long long int pointer. The first character in the accepted string denotes the sign
 * of the binary number. In case of a non binary char input, the return value is 1. In case of
 * overflow the return value is 2. Upon success the returnvalue is 0.
 */
int binaryStrToInt(const char * pBinRepr, long long int * const restrict pDecRepr) {
    long long int decRepr = 0;
    
    // Calculate string length en check for invalid characters
    const char * const pBinReprStart = pBinRepr;
    while (*pBinRepr && (pBinRepr - pBinReprStart < sizeof(long long int) * 8)) {
        if (*pBinRepr != '0' && *pBinRepr != '1') {
            // Invalid character detected
            return 1;
        }
        pBinRepr++;
    }
    if (*pBinRepr != '\0') {
        // Overflow detected
        return 2;
    }
    int binDigits = pBinRepr - pBinReprStart;
    pBinRepr = pBinReprStart;
    
    // Process for string length < 2
    if (binDigits == 1) {
        // Only 1 digit so no sign
        if (*pBinRepr == '1') {
            decRepr = 1;
        }
        *pDecRepr = decRepr;
        return 0;
    } else if (binDigits == 0) {
        // No digits means 0
        *pDecRepr = decRepr;
        return 0;
    }
    
    // When we have at least 2 binary digits and thus a sign -->
    
    // Calculate power of 2 for second bit from left in our return data type size (first is the sign)
    long long int pow2 = 1LL << ((sizeof(long long int) * 8) - 2);
    
    // Loop input string bits
    for(char bit; (bit = *pBinRepr) != '\0'; pBinRepr++) {
        // Check first bit in input string
        if (pBinRepr == pBinReprStart) {
            if (bit == '1') {
                // If first bit is 1 then set leftmost bit
                unsigned char shiftAmount = sizeof(long long int) * 8 - 1;
                decRepr |= 1LL << shiftAmount;
                // Set padding 1 bits until we reach the start of the input bits after the sign
                // (needed when return data type is larger than input string length)
                for (unsigned char i = 0; i < ((sizeof(long long int) * 8) - binDigits); i++) {
                    decRepr |= pow2;
                    pow2 >>= 1;
                }
            } else {
                // Shift to next bit until we reach the start of the input bits after the sign
                // (needed when return data type is larger than input string length)
                for (unsigned char i = 0; i < ((sizeof(long long int) * 8) - binDigits); i++) {
                    pow2 >>= 1;
                }
            }
        // Check next bit in input string
        } else {
            if (bit == '1') {
                // Set this bit
                decRepr |= pow2;
            }
            // Shift to next bit
            pow2 >>= 1;
        }
    }
    
    // Set the resulting long long int
    *pDecRepr = decRepr;
    // Set returnvalue of success
    return 0;
}