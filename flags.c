#include "main.h"

/**
 * get_flags - Calculates flags
 * @format: Formatted string
 * @i: get a param
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int a, current_i;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[current_i] == FLAGS_CH[a])
			{
				flag |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*i = current_i - 1;

	return (flag);
}

