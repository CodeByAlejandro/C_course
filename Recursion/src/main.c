#include <stdio.h>
#include <string.h>

int sumUpTo(int n);
int gcd(int num1, int num2);
int gcdAlt(int num1, int num2);
void reverseString(char * restrict revStr, const char * restrict origStr, int strLen);


int main(int argc, char **argv)
{
    int upperBound = 5;
    int recursiveSum = sumUpTo(upperBound);
    printf("The sum of the range of numbers from 1 to %d is %d\n", upperBound, recursiveSum);
    
    int num1 = 80, num2 = 25;
    int recursiveGCD = gcd(num1, num2);
    printf("The greatest common denominator (gcd) of %d and %d is %d\n", num1, num2, recursiveGCD);
    recursiveGCD = gcdAlt(num1, num2);
    printf("The greatest common denominator (gcdAlt) of %d and %d is %d\n", num1, num2, recursiveGCD);
    
    char string[20] = "Alejandro De Groote";
    char revString[20];
    reverseString(revString, string, strlen(string));
    printf("The reverse string of '%s' is '%s'\n", string, revString);

    return 0;
}

int sumUpTo(int n) {
    if (n == 1)
        return 1;
    int sum = n;
    sum += sumUpTo(n-1);
    return sum;
}

int gcd(int num1, int num2) {
    int gcdVal = num1 % num2;
    if (gcdVal == 0)
        return num2;
    else
        return gcd(num2, gcdVal);
}

int gcdAlt(int num1, int num2) {
    if (num1 != num2)
        if (num1 > num2)
            return gcdAlt(num1-num2, num2);
        else
            return gcdAlt(num1, num2-num1);
    else
        return num1;
}

void reverseString(char * restrict revStr, const char * restrict origStr, int strLen) {
    static int i = 0;
    if (*origStr) {
        reverseString(revStr, origStr + 1, strLen);
        revStr[i++] = *origStr;
    }
    if (i == strLen) {
        revStr[i] = '\0';
    }
    return;
}