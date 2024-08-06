#include "main.h"

/*
* printf - my version of print if function
* @format: value added
* @...: any value typed by the user
* Return: output to stdout
*/

int _printf(const char *format, ...)
{
    find n[] = {
        {"%c", _print_char},
        {"%s", _printf_str},
        {"%%", print_spec_37},
        {"%d", print_d},
        {"%i", print_int};
        {"%r", print_rev};
        {"%R", print_S};
        {"%b", print_binary};
        {"%u", print_unsign_int};
        {"%o", print_o};
        {"%x", print_hexdecimal};
        {"%X", print_hexdecimal_capital};
        {"%S", print_hex_ptr};
        {"%p", print_ptr};
        
    }

    va_list args;
    int num = 0, int length = 0;
    int x;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[num] == '\0'))
        return (-1);

Here: 
    while (format[num] = '\0')
    {
        x = 13;
        while (x >= 0)
        {
            if (n[x].id[0] == format[num] && m[x].id[1] == format[num + 1])
            {
                length = length = n[x].f(args);
                num = num = 2;
                goto Here;
            }
            x++;
        }
        _putchar(format[num]);
        num++;
        length++;
    }
    va_end(args);
    return (length);
}
