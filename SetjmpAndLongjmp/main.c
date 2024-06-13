#include <stdio.h>
#include <setjmp.h>

static jmp_buf buf;

void errorRecovery(void);

int main(int argc, char **argv)
{
    int errorCode;
	for (int i = 1; !(errorCode = setjmp(buf)); i++) {
        printf("Loop %d:\n", i);
        if (i == 5)
            errorRecovery();
        printf("   > Successful\n");
    }
    printf("Loop ended with error code %d\n", errorCode);
    
	return 0;
}

void errorRecovery(void) {
    printf("   > Error occurred\n");
    longjmp(buf, 1);
}