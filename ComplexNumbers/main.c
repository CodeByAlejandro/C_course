#include <stdio.h>
#include <complex.h>
#include <math.h> //for math.h floating point functions we need to link with -lm flag (although i didn't have any problems without)

int main(int argc, char **argv)
{
    #ifdef __STDC_NO_COMPLEX__
        printf("Complex numbers are not supported!\n");
    #else
        double complex z1 = I * I;
        printf("I * I : %.1f%+.1fi\n", creal(z1), cimag(z1));
        
        double _Complex z2 = pow(I, 2);
        printf("pow(I, 2) : %.1f%+.1fi\n", creal(z2), cimag(z2));
        
        double PI = acos(-1);
        double complex zEuler = exp(I * PI);
        printf("exp(I*PI) : %.1f%+.1fi\n", creal(zEuler), cimag(zEuler));
        
        double complex z3 = 1 + 2 * I;
        double complex z3Conj = conj(z3);
        printf("Complex number z3Conj: %.1f%+.1fi\n", creal(z3Conj), cimag(z3Conj));
        double complex z4 = 1 - 2 * I;
        double complex z4Conj = conj(z4);
        printf("Complex number z4Conj: %.1f%+.1fi\n", creal(z4Conj), cimag(z4Conj));
        printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z3*z4), cimag(z3*z4));
    #endif
    
	return 0;
}
