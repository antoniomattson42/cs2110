/**
 * @file my_string.c
 * @author Antonio Mattson
 * @collaborators NAMES OF PEOPLE THAT YOU COLLABORATED WITH HERE
 * @brief Your implementation of these famous 3 string.h library functions!
 *
 * NOTE: NO ARRAY NOTATION IS ALLOWED IN THIS FILE
 *
 * @date 2022-03-xx
 */

// DO NOT MODIFY THE INCLUDE(s) LIST
#include <stddef.h>
#include "hw7.h"

/**
 * @brief Calculate the length of a string
 *
 * @param s a constant C string
 * @return size_t the number of characters in the passed in string
 */
size_t my_strlen(const char *s)
{
  int len = 0;
  while(*s != '\0') {
    len = len + 1;
    s = s + 1;
  }
  return len;
}

/**
 * @brief Compare two strings
 *
 * @param s1 First string to be compared
 * @param s2 Second string to be compared
 * @param n First (at most) n bytes to be compared
 * @return int "less than, equal to, or greater than zero if s1 (or the first n
 * bytes thereof) is found, respectively, to be less than, to match, or be
 * greater than s2"
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
  int leng = 0;
  while ((*s1 != '\0') && (*s2 != '\0') && ((size_t)leng < n)) {
    if (*s1 > *s2) {
      return 1;
    }
    if (*s2 > *s1) {
      return -1;
    }
    s1 = s1 + 1;
    s2 = s2 + 1;
    leng = leng + 1;
  }
  if ((*s1 == '\0') && (*s2 != '\0')) {
    return -1;
  }
  if ((*s2 == '\0') && (*s1 != '\0')) {
    return 1;
  }
  return 0;
}

/**
 * @brief Copy a string
 *
 * @param dest The destination buffer
 * @param src The source to copy from
 * @param n maximum number of bytes to copy
 * @return char* a pointer same as dest
 */
char *my_strncpy(char *dest, const char *src, size_t n)
{
  char *final = dest;
  size_t length = 0;
  while ((*src != '\0') && (length < n)) {
    *dest = *src;
    dest = dest + 1;
    src = src + 1;
    n--;
  }
  while (length < n) {
    *dest = '\0';
    dest = dest + 1;
    n--;
  }
  return final;
}
