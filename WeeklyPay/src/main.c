/*
 * author: Alejandro De Groote
 * purpose: Calculate weekly salary
 * 
 */

#include <stdio.h>

#define OVERTIME_START 40
#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_450 .20
#define TAXRATE_REST .25

int main(int argc, char **argv)
{
    // Declare variables
	unsigned char weeklyHours = 0;
    double grossWeeklySalary = 0.00;
    double netWeeklySalary = 0.00;
    double weeklyTaxes = 0.00;
    
    // Request total workhours per week as input
    printf("Please enter amount of weekly workhours : ");
    scanf("%hhu", &weeklyHours);
    
    // Calculate gross weekly salary
    if (weeklyHours <= OVERTIME_START) {
        grossWeeklySalary = weeklyHours * PAYRATE;
    } else {
        // If we have overtime hours, add them at 150%
        grossWeeklySalary = OVERTIME_START * PAYRATE;
        grossWeeklySalary += (weeklyHours - OVERTIME_START) * PAYRATE * 1.50;
    }
    
    // === Calculate total taxation ===
    // 1st taxation level
    if (grossWeeklySalary <= 300) {
        weeklyTaxes = grossWeeklySalary * TAXRATE_300;
    } else {
        // 2nd taxation level
        weeklyTaxes = 300 * TAXRATE_300;
        if (grossWeeklySalary <= 450) {
            weeklyTaxes += (grossWeeklySalary - 300) * TAXRATE_450;
        } else {
            // 3rd taxation level
            weeklyTaxes += 150 * TAXRATE_450;
            weeklyTaxes += (grossWeeklySalary - 450) * TAXRATE_REST;
        }
    }
    
    // Calculate net weekly salary
    netWeeklySalary = grossWeeklySalary - weeklyTaxes;
    
    // Display calculated results
    printf("\n");
    printf("Your gross weekly salary is %f$\n", grossWeeklySalary);
    printf("Your net weekly salary is %f$\n", netWeeklySalary);
    printf("Your weekly taxes amount to %f$\n", weeklyTaxes);
    
	return 0;
}