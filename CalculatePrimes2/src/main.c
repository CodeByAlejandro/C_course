#include <stdio.h>

#define PRIME_UPPER_BOUND 100
#define MAX_PRIMES (PRIME_UPPER_BOUND / 2)

int main(int argc, char **argv) {
	
	int primes[MAX_PRIMES] = { 2, 3 };
	int currPrimesIdx = 2;

	for(int i = 5; i < PRIME_UPPER_BOUND; i+=2) {
		for (int j = 0; i / primes[j] >= primes[j]; j++) {
			if (i % primes[j] == 0) {
				goto nextI;
			}
		}
		primes[currPrimesIdx++] = i;
		nextI: continue;
	}
	
	for(int j = 0; j < MAX_PRIMES && primes[j] != 0; j++) {
		printf("%s%2d", j == 0 ? "" : " ", primes[j]);
	}

	printf("\n\n");

	return 0;
}