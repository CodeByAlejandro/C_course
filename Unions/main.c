#include <stdio.h>

union Grade {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

struct Results {
    union Grade grade;
};

void displayGrade(union Grade grade);

int main(int argc, char **argv)
{
    union Grade grade1, grade2, *pGrade2 = &grade2;
    
    printf("The size of the union in bytes is %zu\n\n", sizeof(union Grade));
    
    grade1.letterGrade = 'A';
    grade1.roundedGrade = 10;
    grade1.exactGrade = 9.5f;
    displayGrade(grade1);
    
    pGrade2->letterGrade = 'A';
    printf("The letter grade is %c\n", pGrade2->letterGrade);
    pGrade2->roundedGrade = 10;
    printf("The rounded grade is %d\n", pGrade2->roundedGrade);
    pGrade2->exactGrade = 9.5f;
    printf("The exact grade is %f\n\n", pGrade2->exactGrade);
    
    struct Results results = {.grade = {.letterGrade = 'B'}};
    printf("The letter grade from struct is %c\n", results.grade.letterGrade);
    
    return 0;
}

void displayGrade(union Grade grade) {
    printf("The letter grade is %c\n", grade.letterGrade);
    printf("The rounded grade is %d\n", grade.roundedGrade);
    printf("The exact grade is %f\n", grade.exactGrade);
    printf("\n");
}