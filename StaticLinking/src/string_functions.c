#include <stddef.h>
#include <ctype.h>

size_t countCharInString(const char * restrict str, char chr) {
    size_t cnt = 0;
    for(; *str; str++) {
        if(*str == chr)
            cnt++;
    }
    return cnt;
}

char * removeNonAlphabeticChars(char * restrict str) {
    char * result = str;
    for(const char * chrP = str; *chrP; chrP++) {
        if(isalpha(*chrP))
            *str++ = *chrP;
    }
    *str = '\0';
    return result;
}

size_t lengthOfString(const char * restrict str) {
    size_t cnt = 0;
    for(; *str; str++, cnt++);
    return cnt;
}

char * strConcat(char * restrict dest, const char * restrict source, size_t n) {
    char * result = dest;
    while(*dest) dest++;
    for(size_t cnt = 0; *source && cnt < n - 1; *dest++ = *source++, cnt++);
    *dest = '\0';
    return result;
}

char * strCopy(char * restrict dest, const char * restrict source, size_t n) {
    char * result = dest;
    for(size_t cnt = 0; *source && cnt < n - 1; *dest++ = *source++, cnt++);
    return result;
}

int substring(char * restrict target, size_t from, size_t n, const char * restrict source) {
    size_t length = lengthOfString(source);
    if(from > length - 1) {
        return 1;
    } else if (n > length - from) {
        return 2;
    }
    for(size_t cnt = 0; cnt < from; cnt++, source++);
    for(size_t cnt = 0; cnt < n; cnt++, *target++ = *source++);
    *target = '\0';
    return 0;
}