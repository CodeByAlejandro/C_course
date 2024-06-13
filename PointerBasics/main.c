#include <stdio.h>

int main(void) {
    
    int number = 0;
    int *pNumber = NULL;
    
    number = 10;
    pNumber = &number;
    
    printf("The address of the pointer is %p\n", &pNumber);
    printf("The address of the number is %p\n", &number);
    printf("The value of the pointer is %p\n", pNumber);
    printf("The value that is pointed to is %d\n", *pNumber);
    printf("The size of the pointer is %zd\n", sizeof(pNumber));
    
    return 0;
}
