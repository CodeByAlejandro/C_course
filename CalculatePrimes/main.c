#include <stdio.h>
#include <stdlib.h>

// Runs for 90 minutes on AMD RX 5800X
#define UPPER_BOUND 10000000000
#define NUMBER_OF_PRIMES 1000000000

int main(int argc, char **argv)
{
    // Declare variables
    long *primes = (long *) malloc((NUMBER_OF_PRIMES) * sizeof(long));
    if (primes == NULL) {
        printf("=> Error with memory allocation\n");
    }
    
    long nbrOfPrimesCalc = 2;
    long cycles = 0;
    
    // Set initial primes in array
    primes[0] = 2;
    primes[1] = 3;
    
    // Loop only uneven numbers since all even numbers are evenly divisable by 2
    // and thus not a prime number
    for (long p = 5; p <= UPPER_BOUND; p+=2) {
        _Bool isPrime = 1;
        long i = 0;
        // Only check against previous prime numbers we already have
        // until we reach the square root of the current evaluated number
        // (no point in going higher than that since those would just be the inverse of those multiplication pairs)
        while (primes[i] != 0 && p / primes[i] >= primes[i]) {
            cycles++;
            // Check if the current number is evenly divisable by the current previous prime number
            // If it is, then the current number is no prime number
            if (p % primes[i] == 0) {
                isPrime = 0;
                break;
            }
            // If we don't know certain yet, just check the next previous prime number until we reach
            // either the end of previous prime numbers or the square root of the current evaluated number
            i++;
        }
        // If we found a prime simply add it to the array and keep track of total prime numbers
        if (isPrime) {
            primes[nbrOfPrimesCalc++] = p;  
        }
    }
    // Print all prime numbers on a single line of output
//    for (int i = 0; i < nbrOfPrimesCalc; i++) {
//        printf("%15d", primes[i]);
//    }
    // Print total number of prime numbers calculated
    printf("\nNumber of primes is %ld\n", nbrOfPrimesCalc);
    // Print total number of cycles needed to calculate
    printf("Number of calculation cycles is %ld\n", cycles);
    
    // Cleanup memory
    free(primes);
    
    // Return from main function with exit code 0
	return 0;
}
