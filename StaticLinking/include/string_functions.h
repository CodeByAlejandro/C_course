#include <stddef.h>

/*
 * Count occurences of a character in a string.
 * 
 * @param str string to search
 * @param chr character to search in string
 * @return size_t - Number of occurrences of character in string
 */
size_t countCharInString(const char * restrict str, char chr);

/*
 * Remove non alphabetic characters from a string.
 * 
 * @param str string to remove non alphabetic characters from
 * @return char * - pointer to modified string
 */
char * removeNonAlphabeticChars(char * restrict str);

/*
 * Count length of string (excl. null-terminator).
 * 
 * @param str string to count length for
 * @return size_t - Lenght of the string (excl. null-terminator)
 */
size_t lengthOfString(const char * restrict str);

/*
 * Concatenate source string to destination string.
 * Concatenates at most n-1 characters.
 * 
 * @param dest   destination string to concatenate source string to
 * @param source source string to concatenate to destination string
 * @param n      max number of characters to concatenate (incl. null-terminator)
 * @return char * - pointer to the destination string
 */
char * strConcat(char * restrict dest, const char * restrict source, size_t n);

/*
 * Copy source string to destination string.
 * Copy at most n-1 characters.
 * 
 * @param dest   destination string to copy source string into
 * @param source source string to copy into destination string
 * @param n      max number of characters to copy (incl. null-terminator)
 * @return char * - pointer to the copy string
 */
char * strCopy(char * restrict dest, const char * restrict source, size_t n);

/*
 * Copy substring denoted by from index and n length from source to target.
 * 
 * @param target target string to store substring into
 * @param from   starting index in source for substring
 * @param n      length of characters in source for substring
 * @param source source string to capture substring from
 * @return int - 0 on success, non-zero integer on failure
 */
int substring(char * restrict target, size_t from, size_t n, const char * restrict source);