#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_GUESS_NBR 20
#define NBR_OF_TRIES 5

void printCurrLocalTime(time_t t);
unsigned char generRandNbr(time_t t);
unsigned char retrieveGuess();
bool checkNbrGuessed(unsigned char guess, unsigned char randNbr);

int main(int argc, char **argv) {
	// Print current local time
	time_t t;
	time(&t);
	printCurrLocalTime(t);

	// Print game info
	printf("\nThis is a guessing game.\n");
	printf("I have chosen a number between 1 and %hhu, which you must guess.\n", MAX_GUESS_NBR);

	// Generate random number
	unsigned char randNbr = generRandNbr(t);

	// Main game loop
	bool guessed = false;
	unsigned char nbrOfTriesLeft = NBR_OF_TRIES;
	while (!guessed && nbrOfTriesLeft > 0) {
		// Print number of tries
		printf("\nYou have %hhu tries left.\n", nbrOfTriesLeft);
		nbrOfTriesLeft--;

		// Retrieve a valid guess from the player
		unsigned char guess = retrieveGuess();

		// Check if number is guessed or not and give a hint if not
		guessed = checkNbrGuessed(guess, randNbr);
	}
	
	if (guessed == false) {
		printf("\nToo bad, you will never guess my number!\n");
	}
	
	printf("\n");
	return 0;
}

void printCurrLocalTime(time_t t) {
	struct tm * localTime = localtime(&t);
	char localTimeStr[20];
	strftime(localTimeStr, sizeof(localTimeStr), "%d/%m/%Y %H:%M:%S", localTime);
	printf("Current local time: %s\n", localTimeStr);
}

unsigned char generRandNbr(time_t t) {
	// Use time to seed rand()
	srand((unsigned) t);

	// Generate random number
	return (unsigned char) rand() % MAX_GUESS_NBR + 1; // 1 - MAX_GUESS_NBR
}

unsigned char retrieveGuess() {
	unsigned char guess;
	bool validGuess = false;
	do {
		printf("Enter a guess: ");
		scanf("%hhu", &guess);
		if (guess < 1 || guess > MAX_GUESS_NBR) {
			fprintf(stderr, "The guess %hhu is not in the range 1 - %hhu !\n", guess, MAX_GUESS_NBR);
		} else {
			validGuess = true;
		}
	} while (!validGuess);
	return guess;
}

bool checkNbrGuessed(unsigned char guess, unsigned char randNbr) {
	if (guess == randNbr) {
		printf("\nCongratulations. You guessed it!\n");
		return true;
	} else {
		printf("Sorry %hhu is wrong. ", guess);
		if (guess > randNbr) {
			printf("My number is less than that.\n");
		} else {
			printf("My number is more than that.\n");
		}
		return false;
	}
}