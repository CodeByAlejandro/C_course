/*
 * LINUS TORVALDS SAYS VLA'S ARE "ACTIVELY STUPID" !!!
 * => "It generates much more code, and much slower code (and more fragile code),
 *     than just using a fixed key size would have done."
 */

#include <stdio.h>

int main(int argc, char **argv)
{
    int size = 0;
	printf("How many numbers should I add? ");
    scanf("%d", &size);
    
    int numbers[size];
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        printf("%d.) ", i + 1);
        scanf("%d", &numbers[i]);
        for (char c; (c = getchar()) != '\n' && c != EOF;);
        sum += numbers[i];
    }
    
    printf("Sum of numbers is %d\n", sum);
    
	return 0;
}
