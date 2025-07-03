#include <stdio.h>
#include <stdlib.h>

union student {
	char letterGrade;
	int roundedGrade;
	float exactGrade;
};

int main(int argc, char **argv) {
	union student s1, student2, *s2 = &student2;
	
	s1.letterGrade = 'A';
	s1.roundedGrade = 9;
	s1.exactGrade = 9.5;
	
	printf("s1 letterGrade: %c\n", s1.letterGrade);
	printf("s1 roundedGrade: %d\n", s1.roundedGrade);
	printf("s1 exactGrade: %f\n", s1.exactGrade);
	
	s2->letterGrade = 'B';
	printf("s2 letterGrade: %c\n", s2->letterGrade);

	s2->roundedGrade = 8;
	printf("s2 roundedGrade: %d\n", s2->roundedGrade);

	s2->exactGrade = 8.6;
	printf("s2 exactGrade: %f\n", s2->exactGrade);

	printf("\n");
	return 0;
}