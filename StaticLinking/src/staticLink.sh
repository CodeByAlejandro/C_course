gcc -c string_functions.c -o string_functions.o
ar rcs libstring_functions.a string_functions.o
gcc -I ../include/ -c main.c -o main.o
gcc main.o -L./ -lstring_functions -o main