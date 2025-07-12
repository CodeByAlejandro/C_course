#include <stdlib.h>
#include <stdio.h>

#ifdef DEBON
  #ifndef DEBLVL
    #define DEBLVL 1
  #endif

  #define DEBUG(level, format, ...) \
    if(level <= DEBLVL) { \
      fprintf(stderr, format, __VA_ARGS__); \
    }
#else
  #define DEBUG(level, format, ...)
#endif

int sum(int x, int y, int z) {
  char c = 2;
  int *a;
  
  DEBUG(1, "sum: x = %d\n", x)
  DEBUG(1, "sum: y = %d\n", y)
  DEBUG(1, "sum: z = %d\n", z)
  DEBUG(3, "sum: (int *) a = %p\n", (void *) a)
  DEBUG(2, "sum: a = %d\n", *a)

  *a = 5;

  DEBUG(2, "sum: a = %d\n", *a)
  DEBUG(1, "sum: result = %d\n", ((c + x + y + z + *a) / 3))

  return (c + x + y + z + *a) / 3;

}

int main(int argc, char *argv[]) {
  int i, j, k;
  int result;

  if (argc == 1) {
     printf("Please specify three numbers as parameters.\n");
     exit(1);
  }

  i = atoi(argv[1]);
  j = atoi(argv[2]);
  k = atoi(argv[3]);

  DEBUG(1, "i = %d\n", i)
  DEBUG(1, "j = %d\n", j)
  DEBUG(1, "k = %d\n", k)

  result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);

  DEBUG(1, "result = %d\n", result)

  printf("%d\n", result);

  return 0;
}
