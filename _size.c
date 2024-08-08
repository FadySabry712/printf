#include "main.h"

/**
 * get_size - Calculates the size
 * @format: Formatted string
 * @i: List of arg
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int current_i = *i + 1;
	int siz = 0;

	if (format[current_i] == 'l')
		siz = S_LONG;
	else if (format[current_i] == 'h')
		siz = S_SHORT;

	if (siz == 0)
		*i = current_i - 1;
	else
		*i = current_i;

	return (siz);
}
