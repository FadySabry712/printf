#include "main.h"

/*
* print_ptr - print the address of a pointer 
* @val: value added
* Return: hex of an address
 */

int print_ptr(va_list val)
{
    void *ptr;
    char *str;
    long int n;
    int j, a;

    ptr = va_arg(val, void *);
    if (ptr == NULL)
    {
        for (j = 0; str[j] != '\0'; j++)
            _putchar(str[j]);
        return (j);
    }
    n = (unsigned long int)ptr;
    _putchar('0');
    _putchar('x');
    a = print_hex_ptr(n);
    return (a + 2);
}
