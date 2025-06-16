#include <stdio.h>

#define PRIME_UPPER_BOUND 100
#define MAX_PRIMES (PRIME_UPPER_BOUND / 2)

int main(int argc, char **argv) {
	
	int primes[MAX_PRIMES] = { 2, 3 };
	int currPrimesIdx = 2;

	for(int i = 5; i < PRIME_UPPER_BOUND; i+=2) {
		for (int * ptr = &primes[0]; i / *ptr >= *ptr; ptr++) {
			if (i % *ptr == 0) {
				goto nextI;
			}
		}
		primes[currPrimesIdx++] = i;
		nextI: continue;
	}
	
	for(int * ptr = &primes[0]; *ptr != 0; ptr++) {
		printf("%s%2d", ptr == &primes[0] ? "" : " ", *ptr);
	}

	printf("\n\n");

	return 0;
}