#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int * p = NULL;
	*p = 4;
	
	printf("%d\n", *p);
	
	return 0;
}