#include "main.h"

/*
* print_S - print some special chars
* @val: value given
* Return: special chars
 */

int print_S(val_list val)
{
    char *str;
    int j, length = 0;
    int value;

    str = va_arg(val, char *);
    if (s == NULL)
    {
        str = "(nul)";
    }
    for (j = 0; str[j] != '\0'; j++)
    {
        if (str[j] < 32 || str[j] >= 127)
        {
            _putchar('\\');
            _putchar('x');
            length = length + 2;
            value = str[j];
            if (value < 16)
            {
                _putchar('0');
                length++;
            }
            length = length + print_HEX(value);
        }
        else 
        {
            _putchar(str[j]);
            length++
        }
    }
    return (length;)
}
