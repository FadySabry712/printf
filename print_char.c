#include "main.h"

/*
* _print_char - print char
* @value: argument 1
* Return: 0 Sucess
*/

int _print_char(va_list value)
{
char s;

s = va_arg(value, int);
_putchar(s);
return (0);
}
