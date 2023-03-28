#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define UNUSED(a) (void)(a)

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define LONG_LENGTH 1
#define SHORT_LENGTH 2

#define B_SIZE 1024
/*
* f_spec - struct for specifiers
* @specifier: specific specifier
* @fn: function associated with the specifier
*
* Description: this struct helps us assign a function
* to a specifier
*/
struct f_spec
{
	char specifier;
	int (*fn)(va_list, char [], int *, int, int, int, int);
};

/*
* f_spec_t - typedef struct for specifiers
*/
typedef struct f_spec f_spec_t;

int _printf(const char *format, ...);
char *replace_with_per(char *s, int i);
char *replace_with_string(char *s, int i, char *str);
char *replace_with_char(char *s, int i, int c);
char * replace_with_int(char *s, int i, int num);
int _print(
	const char * format, char [], va_list ap,
	int *i, int floats, int width, int precision,
	int str_length
);


int print_char(va_list, char [], int *, int, int, int, int);
int print_string(va_list, char [], int *, int, int, int, int);
int print_per(va_list, char [], int *, int, int, int, int);
int print_int(va_list, char [], int *, int, int, int, int);
int print_float(va_list, char [], int *, int, int, int, int);


int set_flag(const char *format, int *i);
int set_width(va_list ap, const char *format, int *i);
int set_precision(va_list ap, const char *format, int *i);
int set_str_length(const char *format, int *i);


int is_digit(char c);
int _strlen(char *s);
#endif /**MAIN_H*/
