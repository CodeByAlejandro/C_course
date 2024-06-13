#include <stdio.h>
#include <stdlib.h>

/* This is a function that returns a pointer to 100 blocks of 100 chars.
 * It also takes a pointer to 100 blocks of 100 chars as parameter.
 * You can think of this as the paranthesis being around the pointer '*'-mark
 * to indicate the pointer applies to the name to the right of it, rather than
 * to the datatype to the left of it. So outside of the pointer parenthesis there
 * is the only the char[100][100] type left. The square brackets for arrays in C
 * always go at the end so because of that the [100][100] is written after the pointer
 * parenthesis.
 */
char (*initStackArr(char (*stackArr)[100][100]))[100][100];
char (*initStackArrEasierSignature(char stackArr[100][100][100]))[100][100];

// This is a function that returns a pointer to a pointer to a pointer to a char (a.k.a. 3D char array)
char ***allocate3DArray(void);
// this is a function that accepts a pointer to a pointer to a pointer to a char (a.k.a 3D char array)
void deallocate3DArray(char ***heapArr);

int main(int argc, char **argv)
{
	char stackArr[100][100][100];
    // Variables stackArrCpy and stackArrCpy2 are unused, but the point is to be able to compile
    char (*stackArrCpy)[100][100] = initStackArr(stackArr);
    char (*stackArrCpy2)[100][100] = initStackArrEasierSignature(stackArr);
    // Variable heapArr is unused, but the point is to be able to compile
    char *** heapArr = allocate3DArray();
    // Deallocate memory again
    // (not really needed since OS will do this automatically upon program execution end)
    deallocate3DArray(heapArr);
	return 0;
    
    /* CONCLUSION 
     * ------------
     * Since the memory layout is different in stack memory,
     * i.e. all consecutive blocks that really just form a big 1D array,
     * only the first dimension decays into a pointer when the array is
     * passed to or returned from a function.
     * 
     * When we dynamically allocate we can only allocate 1D blocks of memory
     * and each time we get a pointer. So in this case we really have arrays of pointers
     * to arrays of pointers to arrays of 100 chars. Each of these arrays at any dimension level
     * can be stored in different locations in memory. So here we need a pointer for each dimension
     * because it's simply not known where the memory for each dimension is stored.
     * 
     * Note that both types of memory will not be initialized by default.
     */
}

char (*initStackArr(char (*stackArr)[100][100]))[100][100] {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                stackArr[i][j][k] = '\0';
            }
        }
    }
    return stackArr;
}

char (*initStackArrEasierSignature(char stackArr[100][100][100]))[100][100] {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                stackArr[i][j][k] = '\0';
            }
        }
    }
    return stackArr;
}

char ***allocate3DArray(void) {
    char ***heapArr = (char ***) malloc(100 * sizeof(char **));
    if (heapArr == NULL) {
        printf("Error allocating memory for pages\n");
    }
    for (int i = 0; i < 100; i++) {
        heapArr[i] = (char **) malloc(100 * sizeof(char *));
        if (heapArr[i] == NULL) {
            printf("Error allocating memory for rows\n");
        }
        for (int j = 0; j < 100; j++) {
            heapArr[i][j] = (char *) malloc(100 * sizeof(char));
            if (heapArr[i][j] == NULL) {
                printf("Error allocating memory for collumns\n");
            }
        }
    }
    return heapArr;
}

void deallocate3DArray(char ***heapArr) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            free(heapArr[i][j]);
        }
        free(heapArr[i]);
    }
    free(heapArr);
}