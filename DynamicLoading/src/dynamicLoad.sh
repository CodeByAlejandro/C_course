gcc string_functions.c -fPIC -shared -o libstring_functions.so
gcc dynamicLoading.c -ldl -o main
# No need to change LD_LIBRARY_PATH here since an absolute path is used in the dlopen() call
# (and the libdl library for the dynamic loading itself is present in a default system lib dir)