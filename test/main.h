#ifndef _CUSTOM_PRINTF_H
#define _CUSTOM_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUT_BUF_SIZE 1024
#define BUF_FLUSH_MODE -1
#define NULL_STR "(null)"
#define INIT_PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define TO_LOWERCASE 1
#define UNSIGNED_CONV 2

/* Structure for parameter management */
typedef struct parameter
{
    unsigned int isUnsigned: 1;
    unsigned int plus: 1;
    unsigned int space: 1;
    unsigned int hashtag: 1;
    unsigned int zero: 1;
    unsigned int minus: 1;
    unsigned int widthVal;
    unsigned int precisionVal;
    unsigned int hMod: 1;
    unsigned int lMod: 1;
} param_t;

/* Structure for specifier management */
typedef struct spec
{
    char *specStr;
    int (*funcPtr)(va_list, param_t *);
} spec_t;

/* Functions in _put.c */
int custom_puts(char *str);
int custom_putchar(int c);

/* Functions in print_functions.c */
int display_char(va_list ap, param_t *params);
int display_int(va_list ap, param_t *params);
int display_string(va_list ap, param_t *params);
int display_percent(va_list ap, param_t *params);
int display_S(va_list ap, param_t *params);

/* Functions in number.c */
char *num_convert(long int num, int base, int flags, param_t *params);
int display_unsigned(va_list ap, param_t *params);
int display_address(va_list ap, param_t *params);

/* Functions in specifier.c */
int (*fetch_specifier(char *s))(va_list ap, param_t *params);
int fetch_print_func(char *s, va_list ap, param_t *params);
int fetch_flag(char *s, param_t *params);
int fetch_modifier(char *s, param_t *params);
char *fetch_width(char *s, param_t *params, va_list ap);

/* Functions in convert_number.c */
int display_hex(va_list ap, param_t *params);
int display_HEX(va_list ap, param_t *params);
int display_binary(va_list ap, param_t *params);
int display_octal(va_list ap, param_t *params);

/* Functions in simple_printers.c */
int print_range(char *start, char *stop, char *except);
int reverse_print(va_list ap, param_t *params);
int rot13_print(va_list ap, param_t *params);

/* Functions in print_number.c */
int is_digit(int c);
int str_length(char *s);
int print_num_str(char *str, param_t *params);
int print_num_rshift(char *str, param_t *params);
int print_num_lshift(char *str, param_t *params);

/* Functions in params.c */
void set_params(param_t *params, va_list ap);

/* Functions in string_fields.c */
char *fetch_precision(char *p, param_t *params, va_list ap);

/* Functions in _printf.c */
int _printf(const char *format, ...);

#endif

