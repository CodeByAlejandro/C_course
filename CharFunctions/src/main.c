#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct fileStats {
	int cntChars;
	int cntWords;
};

int getFileStatsForFile(struct fileStats * fStats, const char * filePath);
int getFileStatsForStdin(struct fileStats * fStats);
int getFileStatsForStream(struct fileStats * fStats, FILE * fp);
void printFileStats(struct fileStats * fStats);


int main(int argc, char **argv) {
	struct fileStats fStats = { 0, 0 };

	int success = 0;
	if(argc > 1) {
		success = getFileStatsForFile(&fStats, argv[1]);
	} else {
		success = getFileStatsForStdin(&fStats);
	}
	
	if(success == 0) {
		printFileStats(&fStats);
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}

int getFileStatsForFile(struct fileStats * fStats, const char * filePath) {
	FILE * fp = fopen(filePath, "r");
	if(fp) {
		int success = getFileStatsForStream(fStats, fp);
		fclose(fp);
		if(success == 0) {
			return EXIT_SUCCESS;
		} else {
			fprintf(stderr, "Could not get file stats from file \"%s\"!\n", filePath);
			return EXIT_FAILURE;
		}
	} else {
		fprintf(stderr, "Could not open file \"%s\" for reading!\n", filePath);
		return EXIT_FAILURE;
	}
}

int getFileStatsForStdin(struct fileStats * fStats) {
	int success = getFileStatsForStream(fStats, stdin);
	if(success == 0) {
		return EXIT_SUCCESS;
	} else {
		fprintf(stderr, "Could not get file stats from standard input!\n");
		return EXIT_FAILURE;
	}
}

int getFileStatsForStream(struct fileStats * fStats, FILE * fp) {
	bool inWord = false;
	for(int c; (c = fgetc(fp)) != EOF; (fStats->cntChars)++) {
		if(inWord && isspace(c)) {
			(fStats->cntWords)++;
			inWord = false;
		} else if(!inWord && !isspace(c)) {
			inWord = true;
		}
	}
	if(ferror(fp))
		return EXIT_FAILURE;
	else
		return EXIT_SUCCESS;
}

void printFileStats(struct fileStats * fStats) {
	printf("\nThe input contains:\n");
	printf("\t%d %s\n", fStats->cntChars, fStats->cntChars == 1 ? "character" : "characters");
	printf("\t %d %s\n\n", fStats->cntWords, fStats->cntWords == 1 ? "word" : "words");
}