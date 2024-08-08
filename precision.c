#include "main.h"

/**
 * get_precision - Calculates the precision for print
 * @format: Formatted string in which to print the arg
 * @i: List of arguments to be printed
 * @list: list of arg
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int current_i = *i + 1;
	int prec = -1;

	if (format[current_i] != '.')
		return (prec);

	prec = 0;

	for (current_i += 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			prec *= 10;
			prec += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current_i - 1;

return (prec);
}

