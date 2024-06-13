#include <stdio.h>

void square(float *number);

int main(void) {
    
    float number = 3.0;
    square(&number);
    
    printf("The square of the given number is %f\n", number);
    
    return 0;
}

void square(float *number) {
    *number *= *number;
}