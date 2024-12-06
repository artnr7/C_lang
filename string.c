#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str1[5] = "abcd";
  char str2[7] = "zxcvbn";
  printf("%s\n---\n", strncpy(str1, str2, 5));
  printf("-----------");
  printf("%s\n---\n\n", s21_strncpy(str1, str2, 5));

  return 0;
}

char *s21_strncpy(char *toHere, const char *fromHere, size_t n) {
  int flag1 = 0, flag2 = 0, flag3 = 0;
  size_t cntr = 0;
  while (flag1 && flag2 && flag3) {
    if (*toHere == '\0')
      flag1 = 0;
    else if (*fromHere == '\0')
      flag2 = 0;
    if (cntr < n) flag3 = 0;
    if (flag1 && flag2 && flag3) *toHere++ = *fromHere++;
  }
  return toHere;
}

// char *s21_strncpy(char *toHere, const char *fromHere, size_t n) {
//  char *ptr = dest;
//  size_t i = 0;
//  while (*fromHere != '\0' && i < n) {
//   *ptr++ = *str++;
//  }
//  *ptr = '\0';
//  return toHere;
// }

size_t s21_strcspn(const char *str, const char *reject) {
  int flag = 1, cntr = 0;
  while (flag || str[cntr] != '\0') {
    int i = 0;
    while (flag || reject[i] != '\0') {
      if (str[cntr++] == reject[i++]) flag = 0;
    }
  }
  return cntr;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  size_t cntr = 0;
  while (*str1 && (*str1 == *str2) && cntr < n) {
    str1++;
    str2++;
    cntr++;
  }

  return *str1 - *str2;
}

// int s21_strncmp(const char *str1, const char *str2, size_t n) {
//   size_t cntr = 0;
//   while (*str1 && (*(str1++) == *(str2++)) && (cntr++) < n) {
//   }
//   return *str1 - *str2;
// }

size_t s21_strlen(const char *str) {
  size_t cntr = 0;
  while (str[cntr++] != '\0') {
  };
  return cntr;
}

void *s21_memchr(const void *str, int c, size_t n) {
  int flag = 1;
  size_t cntr = 0;
  while (flag) {
    if (str[cntr++] == c) flag = 0;
  }
  if (!flag) str = NULL;
  return str;
}

void *s21_memcmp(const void *str1, const void *str2, size_t n) {
  const unsigned char *ptr1 = str1;
  const unsigned char *ptr2 = str2;
  size_t cntr = 0;

  while (*ptr1 == *ptr2 && cntr < n) {
  }
  return *ptr1 - *ptr2;
}

void *s21_memset(void *str, int c, size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  size_t cntr = 0;
  while (cntr < n) {
    ptr[cntr++] = c;
  }
  return str;
}

void *s21_strncat(char *dest, const char *src, size_t n) {
  size_t cntr = 0;
  while (*dest) dest++;
  while (*src && cntr < n) *dest++ = *src++;
  *dest = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  int flag = 0;
  char *sym;
  char ch = (char)c;
  while (*str != '\0' && flag == 0) {
    if (*str == ch) {
      sym = (char *)str;
      flag = 1;
    }
    str++;
  }
  if (ch == '\0') {
    sym = (char *)str;
  }
  return sym;
}

void *s21_strrchr(const char *str, int c) {
  int flag = 1;
  char *sym;
  char ch = (char)c;
  char *beg_ch = str;
  while (*str != '\0') str++;
  while (str != beg_ch && flag) {
    if (*str == ch) {
      sym = (char *)str;
      flag = 0;
    }
    str--;
  }
  if (ch == '\0') {
    sym = (char *)str;
  }
  return sym;
}

char *s21_strstr(char *string, char *searchstr) {
  char *result = 0;
  int flag = 1;

  if (*searchstr != '\0' && *string != '\0') {
    while (*string && flag) {
      const char *str1 = string;
      const char *str2 = searchstr;
      while (*str2 && (*str1 == *str2)) {
        str1++;
        str2++;
      }

      if (*str2 == '\0') {
        result = string;
        flag = 0;
      }

      string++;
    }
  }
  return result;
}

// char *s21_strstr(const char *str_a, const char *str_b) {
//     char *string;
//     if (*str_b == '\0') {
//         string = (char *)str_a;
//     } else {
//         while (*str_a != '\0') {
//             const char *h = str_a;
//             const char *n = str_b;
//             while (*h != '\0' && *n != '\0' && *h == *n) {
//                 h++;
//                 n++;
//             }
//             if (*n == '\0') {
//                 string = (char *)str_a;
//             }
//             str_a++;
//         }
//     }
//     return string;
// }

char *s21_strtok(char *str, char *delim) {  // функция Ромы
  if (*str == '\n') {
    return 0;
  }
  static char *token_next;
  if (str != NULL) {
    token_next = str;
  }
  char *char_str = token_next;
  while (*char_str && s21_strchr(delim, *char_str)) {
    char_str++;
  }
  if (*char_str == '\0') {
    token_next = NULL;
    return 0;
  }
  char *token_end = char_str;
  while (*token_end && !s21_strchr(delim, *token_end)) {
    token_end++;
  }
  if (*token_end) {
    *token_end = '\0';
    token_next = token_end + 1;
  } else {
    token_next = NULL;
  }
  return char_str;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 1;
  while (flag && *str1 != '\0') {
    while (str2 != '\0') {
      if (*str1 == *str2++) {
        flag = 0;
      }
    }
    str1++;
  }
  if (flag) str1 = NULL;
  return str1;
}

void *to_upper(const char *str) {
  size_t str_length =
      s21_strlen(str);  // надо юзать s21_strlen чтобы узнать n для s21_strncat
  char *ptr = ;      // надо юзать s21_strncat чтобы скопировать str в ptr
  int flag = 1;
  while (flag && *str != '\0') {
    if (*str >= 97 && *str <= 122) {
      ptr = *(str++ - 32);
    }
  }
  return ptr;
}

void *to_lower(const char *str) {
  char *ptr = str;
  int flag = 1;
  while (flag && *str != '\0') {
    if (*str >= 65 && *str <= 90) {
      *ptr++ = *(str++ + 32);
    }
  }
  return ptr;
}

void *insert(const char *src, const char *str, size_t start_index) {
  char *ptr = str;
  size_t cntr = 0;
  int flag = 1;
  while (flag && *str != '\0') {
    ptr[start_index] = *str;
  }
  return ptr;
}

// void *trim(const char *src, const char *trim_chars) пока хз как работает эта
// функция