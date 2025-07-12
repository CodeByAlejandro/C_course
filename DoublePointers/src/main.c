#include <stdio.h>
#include <stdlib.h>

void allocateMemory(int **ptr);

int main(int argc, char **argv) {
	int a = 10, *b = &a, **c = &b;

	printf("a = %d\n", a);
	printf("a = %d\n", *b);
	printf("a = %d\n", **c);
	printf("a = %d\n", ***&c);
	
	printf("b = %p\n", (void *) b);
	printf("b = %p\n", (void *) &a);
	printf("b = %p\n", (void *) *c);
	printf("b = %p\n", (void *) **&c);
	
	printf("c = %p\n", (void *) c);
	printf("c = %p\n", (void *) &b);
	
	printf("**c = %d\n", **c);
	printf("**c = %d\n", *b);
	printf("**c = %d\n", a);

	printf("&c = %p\n", (void *) &c);

	int * ip = NULL;
	allocateMemory(&ip);
	printf("*ip = %d\n", *ip);
	free(ip);

	printf("\n");
	return 0;
}

void allocateMemory(int **ptr) {
	*ptr = (int *) malloc(sizeof(int));
	**ptr = 5;
}