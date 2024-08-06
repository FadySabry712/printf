#include "main.h"

/*
* print_rev - print a reversed string
* @val: value to be reversed
* Return: reversed string
*/

int print_rev(va_list val)
{
    char *str = va_arg(val, cahr *);
    int n;
    int i = 0;

    if (str == NULL)
        s = "(null)"
    while (str[i] != '\0')
        n++;
    for (n = i - 1; n >= 0; n--)
        _putchar(str[n]);
    return (i);
}
