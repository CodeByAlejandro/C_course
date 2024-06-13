#include <stdio.h>

static void myFunc(void);

static double x2 = 2.0;

float x3 = 3.0f;

int main(int argc, char **argv)
{
	auto int x1 = 1;
    
    static float x4 = 4.0f;
    
    register int x5 = 5;
    
	return 0;
}

static void myFunc(void) {
    printf("Hey I'm static\n");
}
