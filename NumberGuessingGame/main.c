/*
 * Author: Alejandro De Groote
 * Description: This is a number guessing game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRIES 5
#define LOWER_BOUND 1
#define UPPER_BOUND 20

int main(int argc, char **argv)
{
    printf("**********************************************\n");
    printf("* This is a little number guessing game:     *\n");
    printf("* I will think of a number between 1 and 20, *\n");
    printf("* including these boundary values. You get 5 *\n");
    printf("* tries to guess my number. Good luck! ;)    *\n");
    printf("**********************************************\n");
    
    // Set seed for random number, based on time
    time_t t;
    srand((unsigned) time(&t));
    // Determine random number
    unsigned char magicNbr = rand() % UPPER_BOUND + LOWER_BOUND; // modulo for upper bound and addition for lower bound
    
    //printf("\nThe magic number is %hhu\n", magicNbr);
    
    for (unsigned char i = 0; i < TRIES; i++) {
        printf("\nYou have %hhu %s left.\n", 5 - i, 5 - i == 1 ? "try" : "tries");
        
        int guess = 0;
        int validAnswers = 0;
        _Bool firstInputAttempt = 1;
        do {
            if (!firstInputAttempt) {
                printf("Please enter a valid integer number between 1 and 20 (inclusive)!\n");
                /* In case some alphanumeric characters were entered, 
                 * make sure to remove them from stdin, 
                 * to prevent scanf from picking them up on the next iteration
                 */
                for (int c; (c = getchar()) != '\n' && c != EOF;);
            } else {
                firstInputAttempt = 0;
            }
            printf("Enter a guess: ");
            validAnswers = scanf("%d", &guess);
        } while (validAnswers < 1 || guess < LOWER_BOUND || guess > UPPER_BOUND);
        
        if (guess < magicNbr) {
            printf("Sorry %d is wrongh. My number is greater than that.\n", guess);
        } else if (guess > magicNbr) {
            printf("Sorry %d is wrongh. My number is less than that.\n", guess);
        } else if (guess == magicNbr) {
            printf("\nCongratulations. You guessed it!\n");
            break;
        }
    }
    
	return 0;
}