gcc string_functions.c -fPIC -shared -o libstring_functions.so
gcc dynamicLoading.c -ldl -o main