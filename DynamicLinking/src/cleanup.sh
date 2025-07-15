# source this script to allow setting env variables!
rm -v *.o *.so main 2>/dev/null
export LD_LIBRARY_PATH=$OLD_LIBRARY_PATH
unset OLD_LIBRARY_PATH