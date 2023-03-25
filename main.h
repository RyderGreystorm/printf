#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

int _printf(const char *format, ...);
char *replace_with_per(char *s, int i);
char *replace_with_string(char *s, int i, char *str);
char *replace_with_char(char *s, int i, char c);
#endif /**MAIN_H*/
