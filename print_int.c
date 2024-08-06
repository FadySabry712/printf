#include "main.h"

/**
 * print_int - prints integer to stdout
 * @args: args to be printed
 * Return: ints to stdout
 */

int print_int(val_list args)
{
    int i = va_arg(args, int);
    int number, l = n % 10, d, e = 1;
    int j = 1;

    i = i / 10;
    number = i;

    if (l < 0)
    {
        _putchar('-');
        number = -number;
        i = -i;
        l = -l;
        j++;
    }

    if (number > 0)
    {
        while (number / 10 != 0)
        {
            e = e * 10;
            number = number / 10;
        }

        number = i;
        while (e > 0)
        {
            d = number / e;
            _putchar(d + '0');
            number = number - (d * e);
            e = e / 10;
            j++;
        }
    }
    _print_char(l + '0');

    return (j);
}

#include "main.h"

/**
 * print_d - prints integer to stdout
 * @args: args to be printed
 * Return: ints to stdout
 */

int print_d(val_list args)
{
    int i = va_arg(args, int);
    int number, l = n % 10, d, e = 1;
    int j = 1;

    i = i / 10;
    number = i;

    if (l < 0)
    {
        _putchar('-');
        number = -number;
        i = -i;
        l = -l;
        j++;
    }

    if (number > 0)
    {
        while (number / 10 != 0)
        {
            e = e * 10;
            number = number / 10;
        }

        number = i;
        while (e > 0)
        {
            d = number / e;
            _putchar(d + '0');
            number = number - (d * e);
            e = e / 10;
            j++;
        }
    }
    _print_char(l + '0');

    return (j);
}
