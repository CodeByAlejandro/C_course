#include <stdio.h>
#include <stdlib.h>

int printIntToBinStrConv(long long int decRepr);
int intToBinaryStr(long long int decRepr, char ** const restrict ppBinReprResult);

int main(int argc, char **argv)
{
	long long int x = 10;
    long long int y = 11;
    printIntToBinStrConv(~x); // 0...1010 -> 1...0101 -> -11
    printIntToBinStrConv(~y); // 0...1011 -> 1...0100 -> -12
    printIntToBinStrConv(x & y); // 1010 1011 -> 1010 -> 10
    printIntToBinStrConv(x | y); // 1010 1011 -> 1011 -> 11
    printIntToBinStrConv(x ^ y); // 1010 1011 -> 0001 -> 1
    printIntToBinStrConv(x << 2); // 1010 -> 0010 1000 -> 40
    printIntToBinStrConv(x >> 2); // 1010 -> 0010 -> 2
	return 0;
}

int printIntToBinStrConv(long long int decRepr) {
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