#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

void static inline func1(float b) {
    printf ("%lf\n",b*2);
}

noreturn void noReturn(void) {
    exit(1);
}
 
int main()  {
     func1(2.2);
     noReturn();
     return 0;
}