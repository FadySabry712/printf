#include "main.h"

/**
 * _printf_str - print a string to stdout
 * @val: argument 1
 * Return: 0 sucess
*/

int _printf_str(va_list val)
{
    char *s;
    int len;
    int n;

    s = va_arg(val, char *);
    if (s == NUll)
    {
        s = "(null)";
        len = _str_len(s);
        for(i = 0; i < len; i++)
            {
                _putchar(s[i]);
            }
        return (len);
    }
    else
    {
        len = _str_len(s);
        for (i = 0; i < len; i++)
            {
                _putchar(s[i]);
            }
        return (len);
    }
}
