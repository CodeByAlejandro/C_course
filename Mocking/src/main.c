#include <stdio.h>
#include <stdlib.h>

#include "enable_testing.h"

int main(int argc, char **argv) {
	
	#ifdef TEST
		#include "test_code.h"
		test_code();
	#else
 		#include "code.h"
		int x = add_triplet(1, 2, 3);
		printf("%d\n", x);
	#endif

	printf("\n");
	return 0;
}