#include <stdio.h>
#include <stdlib.h>
#include "code.h"
#include "test_code.h"

int main(int argc, char **argv) {
	add_triplet(1, 2, 3);

	test_add_triplet_mock_func();
	test_add_triplet_mock_val();
	test_add_triplet_mock_real();

	printf("\n");
	return 0;
}