#ifndef "MAIN_H"
#define "MAIN_H"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct main - data structure to match specsfier
 * @id: param 1 array id
 * @print: param 2 function print
 * Return: used datat structure
 */

typedef struct main
{
char *id;
int (*print)();
} find;

int _putchar(char c);
int _printf(const char *format, ...);
int _print_char(va_list value);
int _printf_str(va_list val);
int _str_len(char *s);
int _str_len_cons(const char *s);
int print_spec_37(void);
int print_int(val_list args);
int print_d(val_list args);
int print_rev(va_list val);
int print_binary(va_list val);
int print_unsign_int(val_list args);
int print_o(va_list val);
int print_hexdecimal(va_list val);
int print_hexdecimal_capital(va_list val);
int print_HEX(unsigned int number);
int print_S(val_list val);
int print_ptr(va_list val);
int print_hex_ptr(unsigned long int n);

#endif /*end if*/
