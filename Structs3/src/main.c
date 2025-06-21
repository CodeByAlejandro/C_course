#include <stdio.h>

struct employee {
	char name[50];
	int hireDate;
	float salary;
};

int main(int argc, char **argv) {

	struct employee employee1 = { .hireDate = 21062025, .salary = 3536.37, .name = "Alejandro" };
	
	struct employee employee2;
	printf("Enter employee data:\n");

	printf("\tname: ");
	if(!fgets(employee2.name, sizeof(employee2.name), stdin)) {
		fprintf(stderr, "Failed to get employee name input!\n");
		return 1;
	}

	// Remove ending newline from name
	char * pChar = employee2.name;
	for (; *pChar != '\n' && *pChar != '\0'; pChar++);
	if (*pChar == '\n')
		*pChar = '\0';
	
	printf("\thireDate: ");
	scanf("%d", &employee2.hireDate);
	printf("\tsalary: ");
	scanf("%f", &employee2.salary);
	
	printf("\n");
	
	printf("List of employees:\n");
	printf("\temployee1:\n");
	printf("\t\tname: %s\n", employee1.name);
	printf("\t\thireDate: %d\n", employee1.hireDate);
	printf("\t\tsalary: %.2f\n", employee1.salary);
	printf("\temployee2:\n");
	printf("\t\tname: %s\n", employee2.name);
	printf("\t\thireDate: %d\n", employee2.hireDate);
	printf("\t\tsalary: %.2f\n", employee2.salary);
	
	printf("\n");
	return 0;
}