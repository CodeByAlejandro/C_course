#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct myArray {
    int length;
    int array[];
};

int main(int argc, char **argv)
{
	struct myArray *pMyArrStruct = NULL;
    int length = 0;
    
    printf("Specify the size of the struct array: ");
    scanf("%d", &length);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    size_t size = sizeof(struct myArray);
    pMyArrStruct = (struct myArray*) malloc(size + length * sizeof(int));
    if (!pMyArrStruct)
        exit(1);
        
    pMyArrStruct->length = length;
    
    for (int i = 0; i < length; i++) {
        pMyArrStruct->array[i] = i;
    }
    
    for (int i = 0; i < length; i++) {
        printf("%d ", pMyArrStruct->array[i]);
    }
    printf("\n");
    
    free(pMyArrStruct);
    
	return 0;
}
