#include <stdio.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char fullname[50];
    struct Date hireDate;
    float salary;
};

struct Employee* reqNewEmployee(struct Employee *const pEmpl);
void printEmployeeInfo(const struct Employee *const pEmpl);
void removeEndingNewlineFromStr(char *str);

int main(void) {
    struct Employee empl1 = {
        "Alejandro De Groote",
        {25, 5, 2024},
        8423.74
    };
    printEmployeeInfo(&empl1);
    
    /* STACK */
    // struct employee empl2;
    // reqNewEmployee(&empl2);
    // printEmployeeInfo(&empl2);
    
    /* HEAP */
    struct Employee* pEmpl = (struct Employee*) malloc(10 * sizeof(struct Employee));
    reqNewEmployee(pEmpl);
    printEmployeeInfo(pEmpl);
    free(pEmpl);
    pEmpl = NULL;
    
    return 0;
}

struct Employee* reqNewEmployee(struct Employee *const pEmpl) {
    printf("Please provide the information for another employee:\n");
    
    printf("\tFullname: ");
    fgets(pEmpl->fullname, 50, stdin);
    removeEndingNewlineFromStr(pEmpl->fullname);
    
    printf("\tHire date: ");
    scanf("%d/%d/%d", &pEmpl->hireDate.day, &pEmpl->hireDate.month, &pEmpl->hireDate.year);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    printf("\tSalary: ");
    scanf("%f", &pEmpl->salary);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    printf("\n");
    
    return pEmpl;
}

void printEmployeeInfo(const struct Employee *const pEmpl) {
    printf(
        "Employee:\n\tFullname: %s\n\tHire date: %.2d/%.2d/%.4d\n\tSalary: %.2f\n\n",
        pEmpl->fullname,
        pEmpl->hireDate.day, pEmpl->hireDate.month, pEmpl->hireDate.year,
        pEmpl->salary
    );
}

void removeEndingNewlineFromStr(char *pStr) {
    while (*pStr)
        pStr++;
    pStr--;
    if (*pStr == '\n')
        *pStr = '\0';
}