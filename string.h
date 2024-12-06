#include <stdio.h>

char *s21_strncpy(char *toHere, const char *fromHere, size_t n);
size_t s21_strcspn(const char *str, const char *reject);
int s21_strncmp(const char *str1, const char *str2, size_t n);
int s21_strncmp(const char *str1, const char *str2, size_t n);
size_t s21_strlen(const char *str);
void *s21_memchr(const void *str, int c, size_t n);
void *s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memset(const void *str, int c, size_t n);
void *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
void *s21_strrchr(const char *str, int c);
char *s21_strstr(char *string, char *searchstr);
char *s21_strtok(char *str, char *delim);
char *s21_strpbrk(const char *str1, const char *str2);
void *to_upper(const char *str);
void *to_lower(const char *str);
void *insert(const char *src, const char *str, size_t start_index);