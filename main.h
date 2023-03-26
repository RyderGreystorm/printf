#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
char *replace_with_per(char *s, int i);
char *replace_with_string(char *s, int i, char *str);
char *replace_with_char(char *s, int i, int c);
char * replace_with_int(char *s, int i, int num);
#endif /**MAIN_H*/
