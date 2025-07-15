# source this script to allow setting env variables!
gcc -fPIC string_functions.c -shared -o libstring_functions.so
gcc  -I ../include/ main.c -L./ -lstring_functions -o main # Idem to gcc -I ../include/ -c main.c -o main.o && gcc main.o -L./ -lstring_functions -o main
export OLD_LIBRARY_PATH=$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH