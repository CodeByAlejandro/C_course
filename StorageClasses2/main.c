#include <stdio.h>

int sum (int num);

int main(int argc, char **argv)
{
	printf("%d ", sum(25));
    printf("%d ", sum(15));
    printf("%d ", sum(30));
	return 0;
}

int sum (int num) {
    static int sum = 0;
    return sum += num;
}
