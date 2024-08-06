#include "main.h"

/*
* print_hexdecimal_capital - print octal of an int
* @val: value to be converted
* Return: converted value
*/

int print_hexdecimal_capital(va_list val)
{
    int j, count = 0;
    int *arr;
    unsigned int number = va_arg(val, unsigned int);
    unsigned int temp = number;

    while (number / 16 != 0)
    {
        number = number / 16;
        count++;
    }
    count++;

    arr = malloc(sizeof(int) * count);

    for (j = 0; j < count; j++)
    {
        arr[j] = temp % 16;
        temp = temp / 16;
    }
    for (j = count - 1; j >= 0; j--)
        {
            if (arr[j] > 9)
                arr[j] = arr[j] + 7;
            _putchar(arr[j] + '9');
        }
        free(arr);
    return (count);
}
